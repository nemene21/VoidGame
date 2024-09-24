#include "enemy.hpp"
#include <scene.hpp>

Enemy::Enemy(StateComponent* state_machine, float health, std::string texture, Vector2 position, float radius):
    Actor(texture, position, health),
    flash {0},
    state_machine {state_machine} {

        sprite.shader_bond.set_shader("flash.glsl");

        add_component(state_machine);
        auto players = SceneManager::scene_on->query_in_group("Player");
        target = players[GetRandomValue(0, players.size()-1)];

        area_comp = new AreaComponent(this, radius);
        area_comp->add_layer((int)AreaIndex::ENEMY_HURTBOX);
        area_comp->add_mask_bit((int)AreaIndex::PLAYER_HITBOX);

        area_comp->area_entered.connect([this](Entity* ent) {
            auto hit_by = area_comp->last_entered->entity;
            auto hit_trans = (TransformComponent*)hit_by->get_component(CompType::TRANSFORM);

            health_comp->hurt(30);
            anim_comp->play("hit");
        });
        add_component(area_comp);

        anim_comp = new AnimationComponent(this);
        anim_comp->make_animation("hit", 0.1, false);
        anim_comp->add_event("hit", 0, [this](float anim) {
            flash = 1;
        });
        anim_comp->add_event("hit", 0.1, [this](float anim) {
            flash = 0;
        });
        add_component(anim_comp);
    }

void Enemy::process(float delta) {
    sprite.shader_bond.send_uniform("flash", &flash, sizeof(float), SHADER_UNIFORM_FLOAT);
}
