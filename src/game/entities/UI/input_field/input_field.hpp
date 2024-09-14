#ifndef INPUT_FIELD_H
#define INPUT_FIELD_H
#include <label.hpp>
#include <entity.hpp>
#include <sprites.hpp>
#include <transform_component.hpp>

class InputField: public Entity {
public:
    Label label;
    Sprite edit_cursor;
    int char_on;
    std::string text, default_text;
    TransformComponent* trans_comp;
    InputField(Vector2 position, int fontsize=20, std::string default_text="", std::string start_text="");

    void process(float delta);
};

#endif