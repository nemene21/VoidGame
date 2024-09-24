#ifndef INPUT_FIELD_H
#define INPUT_FIELD_H
#include "../focusable.hpp"

class InputField: public Focusable {
public:
    Label label;
    Sprite edit_cursor;
    int char_on;
    float delete_timer, delete_speed;
    std::string text, default_text;
    InputField(Vector2 position, int fontsize=20, std::string default_text="", std::string start_text="");

    void process(float delta);
};

#endif