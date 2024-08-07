#ifndef PLAYER_H
#define PLAYER_H
#include <entity.hpp>
#include <transform_component.hpp>
#include <animation_component.hpp>
#include <sprites.hpp>
#include <input.hpp>

class Player: public Entity {
public:
    Sprite sprite;
    TransformComponent* trans_comp;
    AnimationComponent* anim_comp;
    Player();

    void process(float delta);
    void private_process(float delta);
};

#endif