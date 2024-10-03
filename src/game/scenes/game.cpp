#include "game.hpp"
#include <entities/UI/input_field/input_field.hpp>
#include <entities/enemies/chaser/chaser.hpp>
#include <entities/background.hpp>
#include <entities/endgate.hpp>

std::string player_username = "";

GameScene::GameScene(): Scene("game_scene"), background {Sprite("320x180.png")},
    start_label {Label({16, 16}, "Waiting for host to start...", 16)} {
    unpackers[(int)PacketType::GENERATION] = [this](Packet* packet) {
        auto cast_packet = reinterpret_cast<GenerationPacket*>(packet);
        generate_level(cast_packet->seed);
    };

    Player::init_weapons();
    Player::init_projectiles();

    if (Networking::is_host) {
        start_label.text = "Space to start, players: ";
    }
    started = false;

    unpackers[(int)PacketType::START_GAME] = [this](Packet* packet) {
        start_game();
    };
}

void GameScene::restart() {
    started = false;
}

void GameScene::start_game() {
    started = true;
    floor_tilemap = new Tilemap({24, 24}, "test_tileset.png");
    floor_tilemap->collider_mode = ColliderBuildMode::OUTER;
    floor_tilemap->renderer.z_coord = -5;
    add_entity(floor_tilemap);

    auto player = new Player(player_username);
    CameraManager::bind_camera(player->camera_comp->get_camera());
    add_synced_entity(player, true);
    
    add_entity(new Background());
    start_label.visible = false;

    if (Networking::is_host) {
        auto pck = Packet{PacketType::START_GAME, true};
        Networking::send(&pck, sizeof(pck), true);
    }
}

void GameScene::process(float delta) {
    if (Networking::active()) {
        Networking::process();

        if (Networking::is_host) {
            start_label.text = "S to start, players: " + std::to_string(
                Networking::get_user_count()
            );
        }
        if (IsKeyPressed(KEY_S) && Networking::is_host && !started) {
            start_game();
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
    std::cout << "sent seed " << seed << std::endl;
    Networking::send(&packet, sizeof(packet), true);
}

void GameScene::generate_enemies(std::set<Vector2> &tiles) {
    if (!Networking::is_host)
        return;

    std::vector<Vector2> tiles_vec(tiles.begin(), tiles.end());
    for (int i = 0; i < 20; i++) {
        Vector2 pos = tiles_vec[rand()%tiles_vec.size()];

        auto enemy = new ChaserEnemy(pos * floor_tilemap->tilesize * 2);
        add_synced_entity(enemy, true);
        std::cout << "me when" << std::endl;
    }
}
void GameScene::generate_endgate(std::set<Vector2> &tiles) {
    std::vector<Vector2> tiles_vec(tiles.begin(), tiles.end());
    Vector2 pos = tiles_vec[rand()%tiles_vec.size()];

    auto gate = new Endgate(pos * floor_tilemap->tilesize * 2);
    add_entity(gate);
}

void GameScene::generate_level(uint64_t seed) {
    srand(seed);
    auto data = GenData{
        50, 60,
        0.75f
    };
    
    if (Networking::is_host)
        send_generation_packet(seed);

    auto floor_tiles = generate_floor_tiles(data);

    for (auto pos: floor_tiles) {
        auto actual_pos = pos*2;
        floor_tilemap->set_tile(actual_pos, 0);
        floor_tilemap->set_tile(actual_pos+Vector2{1, 0}, 0);
        floor_tilemap->set_tile(actual_pos+Vector2{0, 1}, 0);
        floor_tilemap->set_tile(actual_pos+Vector2{1, 1}, 0);
    }
    floor_tilemap->build();

    generate_endgate(floor_tiles);
    generate_enemies(floor_tiles);
}