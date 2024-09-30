#include "endgate.hpp"

Endgate::Endgate(Vector2 pos): sprite {Sprite("next_level.png")} {
    trans_comp = new TransformComponent(this, pos);
}

void Endgate::process(float delta) {
    sprite.update_transform(trans_comp);
}