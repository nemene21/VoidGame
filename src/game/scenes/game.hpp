#ifndef GAME_H
#define GAME_H
#include <scene.hpp>
#include <networking/networking.hpp>
#include <entities/player.hpp>
#include <tilemap_entity.hpp>

class GameScene: public Scene {
public:
    Tilemap* floor_tilemap;

    GameScene();
    void restart();

    void process(float delta);

    void generate_level();
    std::set<Vector2> generate_floor_tiles();
};

#endif