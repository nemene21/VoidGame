#ifndef FOCUSABLE_H
#define FOCUSABLE_H
#include <label.hpp>
#include <entity.hpp>
#include <sprites.hpp>
#include <transform_component.hpp>
#include <input.hpp>
#include <scene.hpp>

class Focusable: public Entity {
public:
    Signal on_focus, on_unfocus;
    TransformComponent* trans_comp;
    bool focused;

    Focusable(Vector2 position);
    void focus();
    void unfocus();
    void focus_on_rect(Vector2 dim, Vector2 centering);
};

#endif