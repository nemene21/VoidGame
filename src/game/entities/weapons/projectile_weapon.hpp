#ifndef PROJECTILE_WEAPON_H
#define PROJECTILE_WEAPON_H
#include <entities/weapons/weapon.hpp>
#include <entities/player_projectiles/player_projectile.hpp>

struct PlayerShot {
    
};

class ProjectileWeapon: public Weapon {
public:
    ProjectileWeapon(int player_id, float firerate, std::string texture);
    void shoot();
};

#endif