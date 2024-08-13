#ifndef GUN_H
#define GUN_H
#include <entities/weapons/projectile_weapon.hpp>

class Gun: public ProjectileWeapon {
public:
    AnimationComponent* anim_comp;
    float player_dist;
    float height;
    float recoil_anim_strength;

    Gun(int player_id, float firerate, float burst_delay, bool automatic, std::string texture, ShotPattern pattern);
    void process(float delta);
    void private_process(float delta);

    std::pair<EntitySyncPacket*, size_t> get_init_packet();
    void receive_init_packet(EntitySyncPacket* packet);
};

#endif