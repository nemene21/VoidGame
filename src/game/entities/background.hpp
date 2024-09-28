#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <entity.hpp>
#include <sprites.hpp>

class Background: public Entity {
public:
    Sprite sprite;
    Background();
    void process(float delta);
};

#endif