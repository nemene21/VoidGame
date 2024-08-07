#include "player.hpp"

Player::Player(): sprite {Sprite("test.png")} {
    sprite.offset.y = -14;
    type = EntityType::PLAYER;
    add_component(new TransformComponent(this, {RandF()*res.x, RandF()*res.y}));
    trans_comp = (TransformComponent*)get_component(CompType::TRANSFORM);

    anim_comp = new AnimationComponent(this);
    anim_comp->make_animation("run", 0.5, true);
    anim_comp->add_keyframe("run", 0, 1, [this](float anim) {
        float dir = trans_comp->velocity.x > 0 ? 1 : -1;
        if (abs(trans_comp->velocity.x) < 10) dir = 0;

        float angle = dir * 22;
        angle += sinf(GetTime()*15) * 10;

        sprite.angle = Lerpi(sprite.angle, angle, 20);
        sprite.scale = Lerpi(sprite.scale, {1, 1}, 20);
    });

    anim_comp->make_animation("idle", 1, true);
    anim_comp->add_keyframe("idle", 0, 1, [this](float anim) {
        Vector2 new_scale = {
            1 + sinf(GetTime() * 10) * 0.2,
            1 + cosf(GetTime() * 10) * 0.2
        };

        sprite.scale = Lerpi(sprite.scale, new_scale, 20);
        sprite.angle = Lerpi(sprite.angle, 0, 20);
    });
    add_component(anim_comp);

    join_group("Player");
}

void Player::process(float delta) {
    sprite.position = trans_comp->position;
}

void Player::private_process(float delta) {
    Vector2 input_dir = InputVectorNormalized("left", "right", "up", "down");
    trans_comp->interpolate_velocity(Vector2Scale(input_dir, 150), 15);

    std::string str = input_dir != Vector2{0, 0} ? "run" : "idle";
    anim_comp->play(str);
}