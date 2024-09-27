#ifndef WEAPON_H
#define WEAPON_H
#include <entity.hpp>
#include <transform_component.hpp>
#include <timer_component.hpp>
#include <sprites.hpp>
#include <particles.hpp>
#include <input.hpp>
#include <scene.hpp>
#include <networking/networking.hpp>

#define WEAPON_INTRO_SPEED 8.f

enum class WeaponID {
    BURST_TEST,
    SHOTGUN_TEST,
    COUNT,
};

class Weapon: public Entity {
public:
    Sprite sprite;
    std::string texture_name;
    int player_id;
    float intro_anim;
    float reload_time;
    bool active;
    bool automatic;

    TransformComponent* trans_comp;

    TimerComponent* timer_comp;
    bool reloaded;

    bool trying_to_shoot();

    Weapon(int player_id, float firerate, bool automatic, std::string texture);
    Vector2 get_player_pos();
    void private_process(float delta);
};

#endif