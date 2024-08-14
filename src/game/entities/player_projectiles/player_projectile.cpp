#include "player_projectile.hpp"

PlayerProjectile::PlayerProjectile(Vector2 pos, Vector2 vel, float width, std::string texture):
    sprite {Sprite(texture)}
    {
    type = EntityType::PLAYER_PROJECTILE;

    trans_comp = new TransformComponent(this, pos);
    trans_comp->velocity = vel;
    add_component(trans_comp);

    area_comp = new AreaComponent(this, width);
    area_comp->add_layer((int)AreaIndex::PLAYER_HITBOX);
    area_comp->add_mask_bit((int)AreaIndex::ENEMY_HURTBOX);
    add_component(area_comp);
}

void PlayerProjectile::process(float delta) {
    sprite.update_transform(trans_comp);
}

void PlayerProjectile::private_process(float delta) {
    trans_comp->angle = atan2(trans_comp->velocity.y, trans_comp->velocity.x) * RAD2DEG;
}

std::pair<EntitySyncPacket*, size_t> PlayerProjectile::get_init_packet() {
    return get_texture_init_packet("test_bullet.png");
}