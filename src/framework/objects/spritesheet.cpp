#include "spritesheet.hpp"

Spritesheet::Spritesheet(
    std::string texture_path, Vector2 sheet_dimensions,
    Vector2 position,
    Vector2 scale,
    float angle
    ): Drawable(position, {0, 0}, scale, angle), texture {TextureManager::get(texture_path)},
       sheet_dimensions {sheet_dimensions}, frame {0, 0} {}

void Spritesheet::draw() {
    DrawTextureSheet(texture.get(), frame, sheet_dimensions, real_pos(), scale, angle, tint);
}