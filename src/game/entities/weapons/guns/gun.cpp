#include "gun.hpp"

Gun::Gun(int player_id, float firerate, float burst_delay, bool automatic, std::string texture, ShotPattern pattern):
    ProjectileWeapon(player_id, firerate, burst_delay, automatic, texture, pattern),
    player_dist {10},
    height {8},
    recoil_anim_strength {6}
    {
    type = EntityType::GUN;

    anim_comp = new AnimationComponent(this);
    anim_comp->make_animation("shoot", 0.2f, false);
    anim_comp->add_keyframe("shoot", 0, 0.2, [this](float anim) {
        anim = Easing::ease_in_out(anim);
        sprite.offset.x = player_dist - sin(anim*PI) * recoil_anim_strength;
        sprite.scale *= Lerpi({0.6, 1.5}, {1, 1}, anim);
    });
    add_component(anim_comp);

    on_shot.connect([this](Entity* ent) {
        // Shoot animation and screenshake
        anim_comp->play("shoot");
        auto vfx = new ParticleEntity(
            "muzzle_flash.json", sprite.position + Vector2Rotate(sprite.offset, trans_comp->angle * DEG2RAD)
        );
        vfx->system.z_coord = 1;
        SceneManager::scene_on->add_synced_entity(vfx, false);

        auto camera_comp = ((Player*)SceneManager::scene_on->get_entity_by_id(this->player_id))
            ->camera_comp;
        camera_comp->shake(4, 0.1, this->trans_comp->angle * DEG2RAD + PI);
    });
}

void Gun::process(float delta) {
    // Position
    sprite.update_transform(trans_comp);
    sprite.offset.x = player_dist;
    
    // Z layering
    sprite.z_coord = (int)(trans_comp->angle > 0);
}

std::pair<EntitySyncPacket*, size_t> Gun::get_init_packet() {
    return get_texture_init_packet(texture_name);
}

void Gun::private_process(float delta) {
    if (!SceneManager::scene_on->has_entity_id(player_id)) {
        return;
    }
    ProjectileWeapon::private_process(delta);

    // Calculates gun angle based on mouse pos
    Vector2 diff = mouse_pos() - trans_comp->position;
    float angle = atan2(diff.y, diff.x);
    trans_comp->angle = angle * RAD2DEG;

    shoot_angle = trans_comp->angle;

    // Interpolates position towards player
    Vector2 player_pos = get_player_pos();

    trans_comp->position = Lerpi(
        trans_comp->position,
        player_pos - Vector2{0.f, height}, 30);

    // Flipping gun when on left
    trans_comp->scale.y = mouse_pos().x > player_pos.x ? 1 : -1;
}