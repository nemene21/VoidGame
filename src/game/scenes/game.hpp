#ifndef GAME_H
#define GAME_H
#include <scene.hpp>
#include <networking/networking.hpp>
#include <entities/player.hpp>

class GameScene: public Scene {
public:
    GameScene();
    void restart();

    void process(float delta);
};

#endif