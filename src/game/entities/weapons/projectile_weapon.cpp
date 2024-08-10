#include "projectile_weapon.hpp"

// Projectile factory, for easy projectile instancing
PlayerProjectileFactory::ProjectileCreateFunction
    PlayerProjectileFactory::registry[(int)PlayerProjectileType::COUNT];

// This adds projectiles to the registry
void PlayerProjectileFactory::setup(PlayerProjectileType key, ProjectileCreateFunction func) {
    registry[(int)key] = func;
}

// This returns a projectile object constructed by a function in the registry
PlayerProjectile* PlayerProjectileFactory::create_projectile(PlayerProjectileType key, float angle) {
    return registry[(int)key](angle);
}

ProjectileWeapon::ProjectileWeapon(int player_id, float firerate, float burst_delay, bool automatic, std::string texture, ShotPattern pattern):
    Weapon(player_id, firerate, automatic, texture),
    burst_timer {0},
    burst_delay {burst_delay},
    burst_on {pattern.size()},
    shoot_angle {0}
    {
    burst = pattern;
}

void spawn_projectile(PlayerShot& data, float angle) {
    // Builds projectile with angle and spread
    PlayerProjectile* projectile = PlayerProjectileFactory::create_projectile(
        data.projectile_key,
        data.angle + (RandF2() * data.spread) + angle
    );
    // Instantiates for all players
    SceneManager::scene_on->add_synced_entity(projectile, false);
}

void ProjectileWeapon::spawn_projectiles() {
    // Doesnt spawn projectiles if all parts of burst have spawned
    if (burst_on == burst.size()) return;
    burst_timer = burst_delay;

    // For every bullet type in pattern
    for (auto data: burst[burst_on]) {
        for (int i = 0; i < data.amount; i++) {
            spawn_projectile(data, shoot_angle);
        }
    }

    burst_on++;
}

void ProjectileWeapon::private_process(float delta) {
    Weapon::private_process(delta);

    // Initiates a shoot procedure is required
    if (trying_to_shoot() && reloaded) {
        shoot();
    }

    // Shoots part of pattern if required
    if ((burst_timer -= delta) < 0) {
        spawn_projectiles();
    }
}

void ProjectileWeapon::shoot() {
    on_shot.emit(this);
    burst_on = 0;
    burst_timer = 0;

    reloaded = false;
    timer_comp->get_timer("reload")->start();
}