#include "player_projectile.hpp"

PlayerProjectile::PlayerProjectile(Vector2 pos, Vector2 vel, float width, std::string texture):
    lifetime {10},
    sprite {Sprite(texture)}
    {
    type = EntityType::PLAYER_PROJECTILE;
    set_name("Player Projectile");

    trans_comp = new TransformComponent(this, pos);
    trans_comp->velocity = vel;
    add_component(trans_comp);

    area_comp = new AreaComponent(this, width);
    area_comp->add_layer((int)AreaIndex::PLAYER_HITBOX);
    area_comp->add_mask_bit((int)AreaIndex::ENEMY_HURTBOX);
    area_comp->area_entered.connect([this](Entity* ent) {
        queue_free();
    });
    add_component(area_comp);

    process(0);
}

void PlayerProjectile::process(float delta) {
    trans_comp->angle = atan2(trans_comp->velocity.y, trans_comp->velocity.x) * RAD2DEG;
    sprite.update_transform(trans_comp);
}

void PlayerProjectile::private_process(float delta) {
    lifetime -= delta;
    if (lifetime < 0) {
        queue_free();
    }
}

std::pair<EntitySyncPacket*, size_t> PlayerProjectile::get_init_packet() {
    return get_texture_init_packet("test_bullet.png");
}