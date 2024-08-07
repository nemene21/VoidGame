#include "player.hpp"

Player::Player(): Actor("test_guy.png", half_res, 100) {
    type = EntityType::PLAYER;
    sprite.offset.y = -22;

    // Player animation
    anim_comp = new AnimationComponent(this);
    anim_comp->make_animation("run", 0.5, true);
    anim_comp->add_keyframe("run", 0, 1, [this](float anim) {

    });

    anim_comp->make_animation("idle", 1, true);
    anim_comp->add_keyframe("idle", 0, 1, [this](float anim) {

    });
    add_component(anim_comp);

    area_comp = new AreaComponent(this, 16);
    area_comp->add_layer((int)AreaIndex::PLAYER_HURTBOX);
    area_comp->add_mask_bit((int)AreaIndex::ENEMY_HITBOX);
    add_component(area_comp);

    collider_comp = new ColliderComponent(this, trans_comp->position, 8, 8);
    collider_comp->add_mask_bit((int)ColliderIndex::TILEMAP);
    add_component(collider_comp);

    camera_comp = new CameraComponent(this);
    add_component(camera_comp);

    join_group("Player");
}

void Player::process(float delta) {
    sprite.position = trans_comp->position;
}

void Player::private_process(float delta) {
    // Camera movement
    Vector2 mouse_offset = mouse_screen_pos() - half_res;

    mouse_offset /= half_res.y; // -1 : 1 range
    if (Vector2Length(mouse_offset) > 1)
        mouse_offset = Vector2Normalize(mouse_offset);

    mouse_offset *= 64; // Zoom
    mouse_offset.y -= 22;

    camera_comp->offset = Lerpi(camera_comp->offset, mouse_offset, 15);

    // Movement
    Vector2 input_dir = InputVectorNormalized("left", "right", "up", "down");
    trans_comp->interpolate_velocity(Vector2Scale(input_dir, 150), 15);

    std::string animation = input_dir != Vector2{0, 0} ? "run" : "idle";
    anim_comp->play(animation);

    int look_dir = mouse_pos().x > trans_comp->position.x ? 1 : -1;
    trans_comp->scale.x = look_dir;
}