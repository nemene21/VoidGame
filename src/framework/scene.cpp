#include <scene.hpp>
#include <entities/weapons/guns/gun.hpp>

// <Scene>
Scene::Scene(std::string name): name {name}, entities {}, entities_by_name {}, entities_by_id {} {
    SceneManager::setup_scene(this);
}

int Scene::entity_count() {
    return entities.size();
}

Entity *Scene::get_entity(std::string name) {
    if (entities_by_name.find(name) == entities_by_name.end()) {
        std::cout << "ERROR - Entity " << name << " not found!" << std::endl;
        exit(1);
    }
    return entities_by_name[name];
}

void Scene::process_entities(float delta) {
    int i = 0;
    while (i != entities.size()) {
        Entity *entity = entities[i];
        if (entity->is_death_queued())
            continue;

        entity->process(delta);
        if (!entity->is_synced() || entity->owned) {
            entity->private_process(delta);
        }

        entity->process_components(delta);
        if (entity->is_synced() && entity->owned) {
            entity->network_update_components();
        }
        i++;
    }

    // Remove dead entities
    for (int i = entities.size()-1; i >= 0; i--) {

        if (entities[i]->is_death_queued()) {
            entities_by_name.erase(entities[i]->get_name());
            if (entities[i]->id != -1)
                entities_by_id.erase(entities[i]->id);

            delete entities[i];
            entities.erase(entities.begin() + i);
        }
    }
}
 
void Scene::draw_entities(float delta) {
    for (Entity *entity: entities) {
        entity->draw(delta);
        entity->draw_components(delta);
    }
}

void Scene::add_entity(Entity* entity) {
    std::string original_name = entity->get_name();
    int i = 2;
    while (entities_by_name.find(entity->get_name()) != entities_by_name.end()) {
        entity->set_name(original_name + std::to_string(i));
        i++;
    }
    entities_by_name[entity->get_name()] = entity;
    if (entity->id != -1)
        entities_by_id[entity->id] = entity;

    entities.push_back(entity);
}

int Scene::get_valid_entity_id() {
    int id = rand32();
    while (entities_by_id.find(id) != entities_by_id.end())
        id = rand32();
    return id;
}

void Scene::sync_entity(Entity* entity) {
    auto packet_data = entity->get_init_packet();

    if (packet_data.first != nullptr)
        Networking::send(packet_data.first, packet_data.second, true);

    else {
        auto packet = EntitySyncPacket{
            PacketType::ENTITY_SYNC,
            true,
            entity->type,
            entity->id,
            entity->owned
        };
        Networking::send(&packet, sizeof(packet), true);
    }
    delete packet_data.first;
}

auto synced_entity_factory = Factory<Entity, std::function<Entity*(EntitySyncPacket*)>>((int)EntityType::COUNT);

void Scene::add_synced_entity(Entity* entity, bool owned) {
    int id = get_valid_entity_id();

    entity->id = id;
    add_entity(entity);
    sync_entity(entity);
}

std::vector<Entity*> Scene::query_in_group(std::string name) {
    std::vector<Entity*> found {};

    for (auto entity: entities) {
        if (entity->is_in_group(name)) found.push_back(entity);
    }
    return found;
}

Entity *Scene::first_in_group(std::string name) {
    for (auto entity: entities) {
        if (entity->is_in_group(name)) return entity;
    }
    return nullptr;
}

void Scene::unload_entities() {
    for (int i = entities.size()-1; i >= 0; i--) {
        entities_by_name.erase(entities[i]->get_name());
        if (entities[i]->id != -1)
                entities_by_id.erase(entities[i]->id);

        delete entities[i];
        entities.erase(entities.begin() + i);
    }
}

const std::vector<Entity*>& Scene::get_entities() {
    return entities;
}

const std::unordered_map<int, Entity*>& Scene::get_entities_by_id() {
    return entities_by_id;
}

bool Scene::has_entity_id(int id) {
    return entities_by_id.find(id) != entities_by_id.end();
}

Entity* Scene::get_entity_by_id(int id) {
    return entities_by_id[id];
}

void Scene::process(float delta) {}

// <Scene Manager>
SceneMap SceneManager::scene_map = {};
Scene*   SceneManager::scene_on = nullptr;

void SceneManager::setup_scene(Scene* scene) {
    scene_map[scene->name] = scene;
}

void SceneManager::set_scene(std::string name) {
    scene_on = scene_map[name];
    scene_map[name]->unload_entities();
    scene_map[name]->restart();
}

void SceneManager::unload(std::string name) {
    delete scene_map[name];
    scene_map.erase(name);
}

void SceneManager::unload_all() {
    std::vector<std::string> to_unload {};
    for (auto& scene_pair: scene_map) {
        to_unload.push_back(scene_pair.first);
    }
    for (auto to: to_unload) unload(to);
}

void SceneManager::init() {
    synced_entity_factory.setup((int)EntityType::PLAYER,
    [](EntitySyncPacket* packet)
        { return new Player(); });

    synced_entity_factory.setup((int)EntityType::GUN,
    [](EntitySyncPacket* packet) {
        auto cast_packet = reinterpret_cast<EntityTextureSyncPacket*>(packet);
        return new Gun(0, 0, 0, false, cast_packet->texture, {}, 0);
    });

    synced_entity_factory.setup((int)EntityType::PLAYER_PROJECTILE,
    [](EntitySyncPacket* packet) {
        auto cast_packet = reinterpret_cast<EntityTextureSyncPacket*>(packet);
        return new PlayerProjectile({0, 0}, {0, 0}, 0, cast_packet->texture);
    });

    synced_entity_factory.setup((int)EntityType::PARTICLE_SYSTEM,
    [](EntitySyncPacket* packet) {
        auto cast_packet = reinterpret_cast<EntityParticleSyncPacket*>(packet);
        auto vfx = new ParticleEntity(cast_packet->system, {0, 0});
        vfx->system.z_coord = cast_packet->z_coord;
        return vfx;
    });

    unpackers[(int)PacketType::ENTITY_SYNC] = [](Packet* packet) {
        auto sync_packet = reinterpret_cast<EntitySyncPacket*>(packet);
        Entity* entity = synced_entity_factory.get(
            (int)sync_packet->entity_type
        )(sync_packet);

        if (!sync_packet->owned && Networking::is_host) {
            entity->owned = true;
        } else {
            entity->owned = false;
        }

        entity->id = sync_packet->id;
        SceneManager::scene_on->add_entity(entity);
    };
    unpackers[(int)PacketType::COMPONENT_UPDATE] = [](Packet* packet) {
        auto update_packet = reinterpret_cast<ComponentUpdatePacket*>(packet);

        Scene* scene_on = SceneManager::scene_on;
        if (!scene_on->has_entity_id(update_packet->entity_id)) {
            return;
        }

        Entity* entity = scene_on->get_entity_by_id(update_packet->entity_id);
        auto component = entity->get_component((ComponentType)update_packet->component_type);

        component->recieve_update(update_packet);
    };
    unpackers[(int)PacketType::ENTITY_NUKE] = [](Packet* packet) {
        auto nuke_packet = reinterpret_cast<EntityNukePacket*>(packet);
        SceneManager::scene_on->get_entity_by_id(nuke_packet->id)->queue_free();
    };
}