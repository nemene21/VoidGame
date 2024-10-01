#ifndef ENDGATE_H
#define ENDGATE_H
#include <entity.hpp>
#include <sprites.hpp>
#include <label.hpp>

class Endgate: public Entity {
public:
    Label button_label;
    Sprite sprite;

    TransformComponent* trans_comp;
    AreaComponent* area_comp;

    bool can_interract;

    Endgate(Vector2 pos);
    void process(float delta);
};

#endif