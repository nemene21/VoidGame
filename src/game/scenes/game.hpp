#ifndef GAME_H
#define GAME_H
#include <scene.hpp>
#include <networking/networking.hpp>
#include <entities/player/player.hpp>
#include <tilemap_entity.hpp>

extern std::string player_username;

struct GenData {
    int min_tiles, max_tiles;
    float change_chance;
};

class GameScene: public Scene {
public:
    Tilemap* floor_tilemap;
    Sprite background;

    GameScene();
    void restart();

    void process(float delta);

    void generate_level(uint64_t seed);
    void generate_enemies(std::set<Vector2> &tiles);
    void generate_endgate(std::set<Vector2> &tiles);
    std::set<Vector2> generate_floor_tiles(GenData& data);
};

#endif