#ifndef ENEMY_H
#define ENEMY_H
#include <entities/actor.hpp>

class Enemy: public Actor {
public:
    StateComponent* state_machine;
    Enemy(StateComponent* state_machine, float health, std::string texture, Vector2 position);
};

#endif