#include "weapon.hpp"
#include <scene.hpp>

Weapon::Weapon(int player_id, float firerate, bool automatic, std::string texture):
    sprite {Sprite(texture)},
    texture_name {texture},
    player_id {player_id},
    intro_anim {0},
    reload_time {1.f/firerate},
    active {true},
    automatic {automatic},
    reloaded {false}
    {
    // Timer component for reloading
    timer_comp = new TimerComponent(this);
    timer_comp->add_timer("reload", reload_time);
    timer_comp->get_timer("reload")->finished.connect([this](Entity* ent) {
        reloaded = true;
    });
    add_component(timer_comp);

    trans_comp = new TransformComponent(this, {0, 0});
    add_component(trans_comp);
    set_name("Player Weapon");
}

Vector2 Weapon::get_player_pos() {
    return ((TransformComponent*)SceneManager::scene_on->get_entity_by_id(player_id)
        ->get_component(CompType::TRANSFORM))->position;
}

void Weapon::private_process(float delta) {
    if (intro_anim == 0) {
        trans_comp->position = get_player_pos();
    }
    if (active) {
        if (IsJustPressed("Swap Weapon") && intro_anim != 0) {
            active = false;
        } else {
            auto player = (Player*)SceneManager::scene_on->get_entity_by_id(player_id);
            auto timer = timer_comp->get_timer("reload");
            player->weapons[player->weapon_equped_index].reload_progress = timer->progress;
        }
        // Increment spawn animation
        intro_anim = fminf(1, intro_anim + delta * WEAPON_INTRO_SPEED);

    } else {
        // Decrement spawn animation and kill the entity when it reaches 0
        intro_anim = fmaxf(0, intro_anim - delta * WEAPON_INTRO_SPEED);
        if (intro_anim == 0) queue_free();
    }
    // Scale spawn animation
    float blend = Easing::back_in(intro_anim);
    trans_comp->scale = {blend, blend};
}

// Takes care of automatic/non automatic cases
bool Weapon::trying_to_shoot() {
    if (!active) return false;
    return ((automatic && IsPressed("Shoot")) || (!automatic && IsJustPressed("Shoot")));
}