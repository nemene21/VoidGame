#include "enemy.hpp"
#include <scene.hpp>

Enemy::Enemy(StateComponent* state_machine, float health, std::string texture, Vector2 position, float radius):
    Actor(texture, position, health),
    state_machine {state_machine} {

        add_component(state_machine);
        auto players = SceneManager::scene_on->query_in_group("Player");
        target = players[GetRandomValue(0, players.size()-1)];

        area_comp = new AreaComponent(this, radius);
        area_comp->add_layer((int)AreaIndex::ENEMY_HURTBOX);
        area_comp->add_mask_bit((int)AreaIndex::PLAYER_HITBOX);

        area_comp->area_entered.connect([this](Entity* ent) {
            auto hit_by = area_comp->last_entered->entity;
            health_comp->hurt(30);
        });
        add_component(area_comp);
    }