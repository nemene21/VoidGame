#include "label.hpp"
#include <misc.hpp>

Font FONT;

Label::Label(
        Vector2 pos,
        std::string text,
        int fontsize,
        Vector2 centering
    ):

    UIDrawable(0, 0, centering),
    text {text},
    fontsize {fontsize}
{
    position = pos;
}

float Label::get_width() {
    float scaled_fontsize = fontsize * scale.y;
    return MeasureTextEx(
        FONT,
        text.c_str(),
        scaled_fontsize,
        scaled_fontsize/8.f
    ).x;
}

float Label::get_height() {
    float scaled_fontsize = fontsize * scale.y;
    return scaled_fontsize;
}

Vector2 Label::get_dimensions() {
    float scaled_fontsize = fontsize * scale.y;
    return MeasureTextEx(
        FONT,
        text.c_str(),
        scaled_fontsize,
        scaled_fontsize/8.f
    );
}

void Label::draw() {
    float scaled_fontsize = fontsize * scale.y;

    DrawTextPro(
        FONT, text.c_str(), 
        position,
        get_dimensions() * centering,
        angle,
        scaled_fontsize, scaled_fontsize / 8.f,
        tint
    );
}