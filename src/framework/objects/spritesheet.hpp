#ifndef SPRITESHEET_H
#define SPRITESHEET_H
#include <sprites.hpp>

class Spritesheet: public Drawable {
protected:
    Vector2 frame;
    Vector2 sheet_dimensions;
    TexturePtr texture;

public:
    Spritesheet(std::string texture_path, Vector2 sheet_dimensions,
        Vector2 position = {0, 0},
        Vector2 scale = {1, 1},
        float angle = 0
    );

    void draw();
};

#endif