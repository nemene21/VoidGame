#include "weapon.hpp"
#include <scene.hpp>

Weapon::Weapon(int player_id, float firerate, std::string texture):
    sprite {Sprite(texture)},
    player_id {player_id},
    intro_anim {0},
    active {true},
    reloaded {true}
    {

    // Timer component for reloading
    timer_comp = new TimerComponent(this);
    timer_comp->add_timer("reload", 1.f/firerate);
    timer_comp->get_timer("reload")->finished.connect([this](Entity* ent) {
        reloaded = true;
    });
    add_component(timer_comp);

    trans_comp = new TransformComponent(this, get_player_pos());
    add_component(trans_comp);
}

Vector2 Weapon::get_player_pos() {
    return ((TransformComponent*)SceneManager::scene_on->get_entity_by_id(player_id)
        ->get_component(CompType::TRANSFORM))->position;
}

void Weapon::process(float delta) {
    if (active) {
        // Increment spawn animation
        intro_anim = fminf(1, intro_anim + delta * WEAPON_INTRO_SPEED);

        if (IsJustPressed("Swap Weapon")) {
            active = false;
        }
    } else {
        // Decrement spawn animation and kill the entity when it reaches 0
        intro_anim = fmaxf(0, intro_anim - delta * WEAPON_INTRO_SPEED);
        if (intro_anim == 0) queue_free();
    }
    // Scale spawn animation
    float blend = Easing::back_in(intro_anim);
    trans_comp->scale = {blend, blend};
}
