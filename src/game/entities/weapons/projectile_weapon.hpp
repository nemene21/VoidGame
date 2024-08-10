#ifndef PROJECTILE_WEAPON_H
#define PROJECTILE_WEAPON_H
#include <entities/weapons/weapon.hpp>
#include <entities/player_projectiles/player_projectile.hpp>

enum class PlayerProjectileType {
    BASE_BULLET,
    COUNT,
};

class PlayerProjectileFactory {
public:
    typedef std::function<PlayerProjectile*(float angle)> ProjectileCreateFunction;
    static ProjectileCreateFunction registry[(int)PlayerProjectileType::COUNT];

    static void setup(PlayerProjectileType key, ProjectileCreateFunction func);
    static PlayerProjectile* create_projectile(PlayerProjectileType key, float angle);    
};

struct PlayerShot {
    PlayerProjectileType projectile_key;
    float angle;
    float spread;
    int amount;
};

typedef std::vector<std::vector<PlayerShot>> ShotPattern;

class ProjectileWeapon: public Weapon {
public:
    ShotPattern burst;
    float burst_timer;
    float burst_delay;
    int burst_on;

    Signal on_shot;

    float shoot_angle;

    ProjectileWeapon(int player_id, float firerate, float burst_delay, bool automatic, std::string texture, ShotPattern pattern);
    void shoot();
    void spawn_projectiles();
    void private_process(float delta);
};

#endif