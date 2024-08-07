#ifndef PLAYER_H
#define PLAYER_H
#include <entities/actor.hpp>

class Player: public Actor {
public:
    CameraComponent* camera_comp;

    Player();
    void process(float delta);
    void private_process(float delta);
};

#endif