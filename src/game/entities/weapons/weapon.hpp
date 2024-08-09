#ifndef WEAPON_H
#define WEAPON_H
#include <entity.hpp>
#include <transform_component.hpp>
#include <timer_component.hpp>
#include <sprites.hpp>
#include <particles.hpp>
#include <input.hpp>

#define WEAPON_INTRO_SPEED 8.f

class Weapon: public Entity {
public:
    Sprite sprite;
    int player_id;
    float intro_anim;
    bool active;

    TransformComponent* trans_comp;

    TimerComponent* timer_comp;
    bool reloaded;

    Weapon(int player_id, float firerate, std::string texture);
    Vector2 get_player_pos();
    void process(float delta);
};

#endif