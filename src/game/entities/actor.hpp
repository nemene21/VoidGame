#ifndef ACTOR_H
#define ACTOR_H
#include <entity.hpp>
#include <sprites.hpp>
#include <particles.hpp>
#include <input.hpp>

#include <collider_component.hpp>
#include <area_component.hpp>
#include <transform_component.hpp>
#include <health_component.hpp>
#include <animation_component.hpp>
#include <camera_component.hpp>
#include <label.hpp>
#include <components/state_component.hpp>

class Actor: public Entity {
public:
    Sprite sprite;
    TransformComponent* trans_comp;
    ColliderComponent*  collider_comp;
    AreaComponent*      area_comp;
    AnimationComponent* anim_comp;
    HealthComponent*    health_comp;

    Actor(std::string texture, Vector2 position, float health);
};

#endif