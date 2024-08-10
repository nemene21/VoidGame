#include "gun.hpp"

Gun::Gun(int player_id, float firerate, float burst_delay, bool automatic, std::string texture, ShotPattern pattern):
    ProjectileWeapon(player_id, firerate, burst_delay, automatic, texture, pattern),
    player_dist {10},
    height {8},
    recoil_anim_strength {6}
    {
    anim_comp = new AnimationComponent(this);
    anim_comp->make_animation("shoot", 0.2f, false);
    anim_comp->add_keyframe("shoot", 0, 0.2, [this](float anim) {
        sprite.offset.x = player_dist - sin(anim*PI) * recoil_anim_strength;
    });
    add_component(anim_comp);

    on_shot.connect([this](Entity* ent) {
        anim_comp->play("shoot");
    });
}

void Gun::process(float delta) {
    sprite.update_transform(trans_comp);
    sprite.offset.x = player_dist;
}

void Gun::private_process(float delta) {
    // Calculates gun angle based on mouse pos
    Vector2 player_pos = get_player_pos();
    Vector2 diff = mouse_pos() - player_pos;

    float angle = atan2(diff.y, diff.x);
    trans_comp->angle = angle * RAD2DEG;

    // Interpolates position towards player
    trans_comp->position = Lerpi(
        trans_comp->position,
        player_pos - Vector2{0.f, height}, 30);
    
    // Z layering
    sprite.z_coord = (int)(player_pos.y < mouse_pos().y);

    // Flipping gun when on left
    trans_comp->scale.y = mouse_pos().x > player_pos.x ? 1 : -1;
}