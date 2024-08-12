#include "game.hpp"

GameScene::GameScene(): Scene("game_scene") {
    unpackers[(int)PacketType::GENERATION] = [this](Packet* packet) {
        auto cast_packet = reinterpret_cast<GenerationPacket*>(packet);
        generate_level(cast_packet->seed);
    };

    Player::init_weapons();
    Player::init_projectiles();
}

void GameScene::restart() {
    floor_tilemap = new Tilemap({24, 24}, "test_tileset.png");
    floor_tilemap->collider_mode = ColliderBuildMode::OUTER;
    floor_tilemap->renderer.z_coord = -5;
    add_entity(floor_tilemap);
}

void GameScene::process(float delta) {
    if (Networking::active()) {
        Networking::process();

        if (IsKeyDown(KEY_G) && Networking::is_host) {
            generate_level(rand64());
        }

        if (IsKeyDown(KEY_L)) {
            for (auto entity: query_in_group("Player")) {
                entity->queue_free();
            }
            Networking::disconnect();
        }

        if (IsKeyPressed(KEY_SPACE)) {
            std::string temp_msg = "Timestamp " + std::to_string(GetTime());
            const char* msg = temp_msg.c_str();
            auto packet = LogPacket{
                PacketType::LOG,
                true,
                ""
            };
            strcpy(packet.message, msg);
            Networking::send(&packet, sizeof(packet), true);
        }
    } else {
        if (IsKeyPressed(KEY_H)) {
            Networking::host();

            auto player = new Player();
            CameraManager::bind_camera(player->camera_comp->get_camera());
            add_synced_entity(player, true);

        } else if (IsKeyPressed(KEY_J)) {
            Networking::join(Networking::get_local_ip());

            auto player = new Player();
            CameraManager::bind_camera(player->camera_comp->get_camera());
            add_synced_entity(player, true);
        }
    }
}

std::set<Vector2> GameScene::generate_floor_tiles() {
    std::set<Vector2> tiles {};
    int steps = 0;
    Vector2 walker_pos = {0, 0};
    Vector2 walker_dir = {1, 0};

    Vector2 dirs[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    walker_dir = dirs[rand()%4];

    while (steps < 256) {
        tiles.insert(walker_pos);

        steps++;
        walker_pos += walker_dir;

        if (RandF() < 0.5f)
            walker_dir = dirs[rand()%4];
    }
    return tiles;
}

void send_generation_packet(uint64_t seed) {
    auto packet = GenerationPacket{
        PacketType::GENERATION,
        true,
        seed
    };
    Networking::send(&packet, sizeof(packet), true);
}

void GameScene::generate_level(uint64_t seed) {
    srand(seed);
    
    if (Networking::is_host)
        send_generation_packet(seed);

    auto floor_tiles = generate_floor_tiles();

    for (auto pos: floor_tiles) {
        floor_tilemap->set_tile(pos, 0);
    }
    floor_tilemap->build();
}