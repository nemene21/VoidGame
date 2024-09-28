#include "game.hpp"
#include <entities/UI/input_field/input_field.hpp>
#include <entities/enemies/chaser/chaser.hpp>
#include <entities/background.hpp>

std::string player_username = "";
float enemy_spawn_timer = 0;

GameScene::GameScene(): Scene("game_scene"), background {Sprite("320x180.png")} {
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

    auto player = new Player(player_username);
    CameraManager::bind_camera(player->camera_comp->get_camera());
    add_synced_entity(player, true);
    
    add_entity(new Background());
}

void GameScene::process(float delta) {
    if (Networking::active()) {
        Networking::process();

        if (Networking::is_host) {
            enemy_spawn_timer -= delta;
            if (enemy_spawn_timer < 0) {
                auto enemy = new ChaserEnemy(Vector2{
                    (float)GetRandomValue(-300, 300), (float)GetRandomValue(-300, 300)
                });
                add_synced_entity(enemy, true);
                enemy_spawn_timer = GetRandomValue(2, 3);
            }
        }
        if (IsKeyPressed(KEY_G) && Networking::is_host) {
            generate_level(rand64());
        }
    }
}

// Walker based level generator
std::set<Vector2> GameScene::generate_floor_tiles(GenData& data) {
    std::set<Vector2> tiles {};
    int steps  = 0,
    step_count = (int)Lerp(data.min_tiles, data.max_tiles, RandF());

    Vector2 walker_pos = {0, 0};
    Vector2 walker_dir = {1, 0};

    Vector2 dirs[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    walker_dir = dirs[rand()%4];

    while (steps < step_count) {
        if (tiles.find(walker_pos) == tiles.end())
            steps++;

        tiles.insert(walker_pos);
        walker_pos += walker_dir;

        if (RandF() < data.change_chance)
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
    auto data = GenData{
        200, 300,
        0.75f
    };
    
    if (Networking::is_host)
        send_generation_packet(seed);

    auto floor_tiles = generate_floor_tiles(data);

    for (auto pos: floor_tiles) {
        floor_tilemap->set_tile(pos, 0);
    }
    floor_tilemap->build();
}