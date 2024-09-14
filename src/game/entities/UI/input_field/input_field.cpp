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
        edit_cursor.make_ui();
    }


void InputField::process(float delta) {
    // TODO: Focusable class that this inherits from, input only when its focused

    label.update_transform_cam(trans_comp);

    if (text != "") {
        label.text = text;
        label.tint = WHITE;
    } else {
        label.text = default_text;
        label.tint = Color{155, 155, 155, 255};
    }

    // Char input
    int key;
    char chr;
    while ((key = GetCharPressed()) > 0) {
        chr = (char)key;
        text.insert(char_on, 1, chr);
        char_on++;
    }

    char_on += (int)IsJustPressed("UI Right") - (int)IsJustPressed("UI Left");
    if (char_on < 0) char_on = 0;
    if (char_on > text.size()) char_on = text.size();

    // Char removal w backspace
    if (IsJustPressed("Delete Char")) {
        if (char_on == 0) goto end;
        
        text.erase(char_on-1, 1);
        char_on--;
    }
    end:

    std::string left_text = text.substr(0, char_on);
    float write_width = MeasureTextEx(FONT, left_text.c_str(), label.fontsize, label.get_spacing()).x;
    
    edit_cursor.update_transform_cam(trans_comp);
    edit_cursor.offset.x = write_width*0.5f + 1;
    edit_cursor.offset.y = label.get_height()*0.25f;
    edit_cursor.scale *= label.fontsize/10.f;
    edit_cursor.visible = sin(GetTime() * PI * 2.f) > 0;
}
