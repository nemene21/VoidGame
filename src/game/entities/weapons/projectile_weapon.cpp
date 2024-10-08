#include "projectile_weapon.hpp"

ProjectileFactory projectile_factory = ProjectileFactory((int)PlayerProjectileType::COUNT);

ProjectileWeapon::ProjectileWeapon(int player_id, float firerate, float burst_delay, bool automatic, std::string texture, ShotPattern pattern, float output_distance):
    Weapon(player_id, firerate, automatic, texture),
    burst_timer {0},
    burst_delay {burst_delay},
    burst_on {pattern.size()},
    shoot_angle {0},
    output_distance {output_distance}
    {
    burst = pattern;
}

void ProjectileWeapon::spawn_projectile(PlayerShot& data, float angle) {
    float vel_angle = data.angle + (RandF2() * data.spread * DEG2RAD) + angle;

    // Builds projectile with angle and spread
    PlayerProjectile* projectile = projectile_factory.get((int)data.projectile_key)(
        trans_comp->position + Vector2Rotate({output_distance, 0}, trans_comp->angle * DEG2RAD),
        Vector2Rotate({750, 0}, vel_angle)
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
            spawn_projectile(data, shoot_angle * DEG2RAD);
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