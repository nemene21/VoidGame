#include "input_field.hpp"

InputField::InputField(
    Vector2 position,
    int fontsize,
    std::string default_text,
    std::string start_text):

    Focusable(position),
    label {Label(position, start_text, fontsize)},
    edit_cursor {Sprite("UI/write_cursor.png")},
    char_on {start_text.size()},
    text {start_text},
    default_text {default_text} {

        edit_cursor.make_ui();
        set_name("Text Input");

        on_focus.connect([this](Entity* ent) {
            float d = mouse_pos().x - trans_comp->position.x;
            char_on = 0;

            while (char_on != text.size()-1) {
                std::string left_text = text.substr(0, char_on+1);
                float len = MeasureTextEx(FONT, left_text.c_str(), label.fontsize, label.get_spacing()).x;
                if (d < len - label.get_spacing()*2.f) {
                    break;
                } else {
                    char_on++;
                }
            }
            float len = MeasureTextEx(FONT, text.c_str(), label.fontsize, label.get_spacing()).x;
            if (d > len - label.get_spacing()*4.f) {
                char_on = text.size();
            }
        });
    }


void InputField::process(float delta) {
    focus_on_rect({res.x, label.get_height()}, label.centering);

    label.update_transform_cam(trans_comp);

    if (text != "") {
        label.text = text;
        label.tint = WHITE;
    } else {
        label.text = default_text;
        label.tint = Color{155, 155, 155, 255};
    }

    std::string left_text = text.substr(0, char_on);
    float write_width = MeasureTextEx(FONT, left_text.c_str(), label.fontsize, label.get_spacing()).x;
    
    edit_cursor.update_transform_cam(trans_comp);
    edit_cursor.offset.x = write_width*0.5f + 1;
    edit_cursor.offset.y = label.get_height()*0.25f;
    edit_cursor.scale *= label.fontsize/10.f;
    edit_cursor.visible = sin(GetTime() * PI * 2.f) > 0;

    if (!focused) {
        edit_cursor.visible = false;
        return;
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
}
