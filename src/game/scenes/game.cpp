#include "game.hpp"

GameScene::GameScene(): Scene("game_scene") {}

void GameScene::restart() {
    floor_tilemap = new Tilemap({24, 24}, "test_tileset.png");
    floor_tilemap->renderer.z_coord = -5;
    add_entity(floor_tilemap);

    generate_level();
}

void GameScene::process(float delta) {
    if (Networking::active()) {
        Networking::process();

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

    while (steps < 256) {
        steps++;
        walker_pos += Vector2Rotate({1, 0}, PI * 0.5 * (rand()%4));

        tiles.insert(walker_pos);
    }
    return tiles;
}

void GameScene::generate_level() {
    auto floor_tiles = generate_floor_tiles();

    for (auto pos: floor_tiles) {
        floor_tilemap->set_tile(pos, 0);
    }
    floor_tilemap->build();
}