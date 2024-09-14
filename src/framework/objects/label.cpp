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
        get_spacing()
    ).x;
}

float Label::get_height() {
    float scaled_fontsize = fontsize * scale.y;
    return MeasureTextEx(
        FONT,
        text.c_str(),
        scaled_fontsize,
        get_spacing()
    ).y;
}

Vector2 Label::get_dimensions() {
    float scaled_fontsize = fontsize * scale.y;
    return MeasureTextEx(
        FONT,
        text.c_str(),
        scaled_fontsize,
        get_spacing()
    );
}

float Label::get_spacing() {
    float scaled_fontsize = fontsize * scale.y;
    return scaled_fontsize / 20.f;
}

void Label::draw() {
    float scaled_fontsize = fontsize * scale.y;

    DrawTextPro(
        FONT, text.c_str(), 
        position,
        get_dimensions() * centering,
        angle,
        scaled_fontsize, get_spacing(),
        tint
    );
}