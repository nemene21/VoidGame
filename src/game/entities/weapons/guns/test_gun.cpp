#include "test_gun.hpp"

Gun *create_test_gun(int player_id) {
    auto gun = new Gun(player_id, 2.f, 0.1f, true, (std::string)"test_gun.png", ShotPattern{
        {PlayerShot{PlayerProjectileType::BASE_BULLET, 0, 8, 1}},
        {PlayerShot{PlayerProjectileType::BASE_BULLET, 0, 8, 1}},
        {PlayerShot{PlayerProjectileType::BASE_BULLET, 0, 8, 1}}
    });
    return gun;
}