#include "input_field.hpp"

InputField::InputField(
    Vector2 position,
    int fontsize,
    std::string default_text,
    std::string start_text):

    Entity("UI Text Input Field"),
    label {Label(position, start_text, fontsize)},
    edit_cursor {Sprite("UI/write_cursor.png")},
    char_on {start_text.size()},
    text {start_text},
    default_text {default_text} {

        trans_comp = new TransformComponent(this, position);
    }


void InputField::process(float delta) {
    // TODO: Focusable class that this inherits from, input only when its focused
    // TODO: Add a writing line thingy

    label.update_transform_cam(trans_comp);

    if (text != "") {
        label.text = text;
        label.tint = WHITE;
    } else {
        label.text = default_text;
        label.tint = Color{155, 155, 155, 255};
    }

    int key;
    char chr;
    while ((key = GetCharPressed()) > 0) {
        chr = (char)key;
        text.insert(char_on, 1, chr);
        char_on++;
    }

    std::string left_text = text.substr(0, char_on);
    float write_width = MeasureTextEx(FONT, left_text.c_str(), label.fontsize, label.fontsize / 5.f).x;
    
    edit_cursor.position = trans_comp->position;
    edit_cursor.position.x += write_width + 4;
    edit_cursor.scale = Vector2{1, 1} * label.fontsize/10.f * trans_comp->scale.x;
    edit_cursor.position.y += label.fontsize * 0.5f * trans_comp->scale.x;
}
