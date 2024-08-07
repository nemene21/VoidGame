#include "game.hpp"

GameScene::GameScene(): Scene("game_scene") {}

void GameScene::restart() {
    
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