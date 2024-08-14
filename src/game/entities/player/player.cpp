#include "player.hpp"
#include <entities/weapons/guns/gun.hpp>

auto weapon_factory = Factory<Weapon, std::function<Weapon*(int)>>((int)WeaponID::COUNT);

Player::Player(): Actor("test_guy.png", {0, 0}, 100),
    run_particles {ParticleSystem("player_run.json")} {
    type = EntityType::PLAYER;
    
    // Drawing data
    sprite.offset.y = -11;
    run_particles.z_coord = -1;
    look_dir = 1;

    // Player animation
    anim_comp = new AnimationComponent(this);

    // Run animation
    anim_comp->make_animation("run", 0.5, true);
    anim_comp->add_keyframe("run", 0, 1, [this](float anim) {
        trans_comp->scale = Lerpi(trans_comp->scale, Vector2{(float)look_dir, 1}, 20);

        float desired_angle = Vector2Normalize(trans_comp->velocity).x;
        desired_angle *= 15;
        desired_angle += sinf(GetTime() * 16) * 12;
        trans_comp->angle = Lerpi(trans_comp->angle, desired_angle, 16);
    });

    // Idle animation
    anim_comp->make_animation("idle", 1, true);
    anim_comp->add_keyframe("idle", 0, 1, [this](float anim) {
        trans_comp->angle = Lerpi(trans_comp->angle, 0, 10);

        Vector2 desired_scale = {
            1 + sinf(GetTime() * 12) * 0.15,
            1 + cosf(GetTime() * 12) * 0.15
        };
        desired_scale.x *= look_dir;

        trans_comp->scale = Lerpi(trans_comp->scale, desired_scale, 20);
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
    // camera_comp->set_zoom(0.5f);
    add_component(camera_comp);

    join_group("Player");
    set_name("Player");
}

void Player::process(float delta) {
    sprite.update_transform(trans_comp);
    run_particles.set_left((int)(Vector2Length(trans_comp->velocity) > 2));
    run_particles.position = trans_comp->position;
}

void Player::private_process(float delta) {
    // Camera movement
    Vector2 mouse_offset = mouse_screen_pos() - half_res;

    mouse_offset /= half_res.y; // -1 : 1 range
    if (Vector2Length(mouse_offset) > 1)
        mouse_offset = Vector2Normalize(mouse_offset);

    mouse_offset *= 64; // Zoom
    mouse_offset.y -= 11;

    camera_comp->offset = Lerpi(camera_comp->offset, mouse_offset, 15);

    // Movement
    Vector2 input_dir = InputVectorNormalized("Left", "Right", "Up", "Down");
    trans_comp->interpolate_velocity(Vector2Scale(input_dir, 150), 15);

    // Animation
    std::string animation = input_dir != Vector2{0, 0} ? "run" : "idle";
    anim_comp->play(animation);

    look_dir = mouse_pos().x > trans_comp->position.x ? 1 : -1;

    // Weapon swapping
    if (IsJustPressed("Swap Weapon")) {
        auto weapon = weapon_factory.get((int)WeaponID::TEST)(id);
        SceneManager::scene_on->add_synced_entity(weapon, true);
    }
}

void Player::init_projectiles() {
    projectile_factory.setup((int)PlayerProjectileType::BASE_BULLET,
        [](Vector2 pos, Vector2 vel) -> PlayerProjectile* {
        auto projectile = new PlayerProjectile(pos, vel, 8, "test_bullet.png");
        return projectile;
    });
}

void Player::init_weapons() {
    weapon_factory.setup((int)WeaponID::TEST, [](int player_id) -> Weapon* {
        auto gun = new Gun(player_id, 2.f, 0.05f, true, (std::string)"test_gun.png", ShotPattern{
            {PlayerShot{PlayerProjectileType::BASE_BULLET, 0, 8, 1}},
            {PlayerShot{PlayerProjectileType::BASE_BULLET, 0, 8, 1}},
            {PlayerShot{PlayerProjectileType::BASE_BULLET, 0, 8, 1}}
        });
        return gun;
    });
}