#include "enemy.hpp"

Enemy::Enemy(StateComponent* state_machine, float health, std::string texture, Vector2 position):
    Actor(texture, position, health),
    state_machine {state_machine} {

        add_component(state_machine);
    }