#ifndef PLAYER_H
#define PLAYER_H
#include <entities/actor.hpp>

class Player: public Actor {
public:
    ParticleSystem run_particles;
    CameraComponent* camera_comp;
    int look_dir;

    Player();
    void process(float delta);
    void private_process(float delta);
};

#endif