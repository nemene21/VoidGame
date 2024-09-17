#include "button.hpp"

Button::Button(Vector2 pos, std::string text):
    Focusable(pos),
    label {Label(pos, text, 20)},
    sprite {Sprite("basic_particle.png")} {}

void Button::process(float delta) {
    focus_on_rect(label.get_dimensions(), label.centering);

    if (focused && IsJustPressed("Click")) {
        on_press.emit(this);
    }
}