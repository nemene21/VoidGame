#ifndef LABEL_H
#define LABEL_H
#include <ui_drawables.hpp>

extern Font FONT;

class Label: public UIDrawable {
public:
    std::string text;
    int fontsize;
    Label(Vector2 pos, std::string text="", int fontsize=11, Vector2 centering={0, 0});
    
    float get_width();
    float get_height();
    Vector2 get_dimensions();

    void draw();
};

#endif