#ifndef PLAYER_PROJECTILE_H
#define PLAYER_PROJECTILE_H
#include <entity.hpp>
#include <sprites.hpp>
#include <particles.hpp>
#include <transform_component.hpp>
#include <area_component.hpp>

class PlayerProjectile: public Entity {
public:
    Sprite sprite;
    TransformComponent* trans_comp;
    AreaComponent* area_comp;
    PlayerProjectile(Vector2 pos, Vector2 vel, float width, std::string texture);
    void process(float delta);
};

#endif