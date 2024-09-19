#include "enemy.hpp"
#include <scene.hpp>

Enemy::Enemy(StateComponent* state_machine, float health, std::string texture, Vector2 position):
    Actor(texture, position, health),
    state_machine {state_machine} {

        add_component(state_machine);
        auto players = SceneManager::scene_on->query_in_group("Player");
        target = players[GetRandomValue(0, players.size()-1)];
    }