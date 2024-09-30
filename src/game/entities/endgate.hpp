#ifndef ENDGATE_H
#define ENDGATE_H
#include <entity.hpp>
#include <sprites.hpp>

class Endgate: public Entity {
public:
    Sprite sprite;
    TransformComponent* trans_comp;
    Endgate(Vector2 pos);
    void process(float delta);
};

#endif