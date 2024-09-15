#ifndef BUTTON_H
#define BUTTON_H
#include "../focusable.hpp"

class Button: public Focusable {
public:
    Signal on_press;
    Label label;
    Sprite sprite;

    Button(Vector2 pos, std::string text="Btn");
    void process(float delta);
};

#endif