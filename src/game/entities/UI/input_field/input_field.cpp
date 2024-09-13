#include "input_field.hpp"

InputField::InputField(
    Vector2 position,
    int fontsize,
    std::string default_text,
    std::string start_text):

    Entity("UI Text Input Field"),
    label {Label(position, start_text, fontsize)},
    text {start_text},
    default_text {default_text} {}


void InputField::process(float delta) {
    if (text != "") {
        label.text = text;
    } else {
        label.text = default_text;
    }

    int chr;
    while ((chr = GetCharPressed()) > 0) {
        text += (char)chr;
    }
}
