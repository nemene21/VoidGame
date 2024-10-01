#include "endgate.hpp"

Endgate::Endgate(Vector2 pos): sprite {Sprite("next_level.png")},
    button_label {Label(pos, "E", 16, {.5, .5})},
    can_interract {false} {
    trans_comp = new TransformComponent(this, pos);

    button_label.offset = {0, -8.0};

    if (!Networking::is_host) return;
    area_comp = new AreaComponent(this, 24);
    area_comp->position = pos;
    area_comp->add_mask_bit((int)AreaIndex::PLAYER_HURTBOX);
    area_comp->area_entered.connect([this](Entity* ent) {
        auto player = area_comp->last_entered->entity;
        if (player->owned) {
            can_interract = true;
        }
    });
    area_comp->area_exited.connect([this](Entity* ent) {
        auto player = area_comp->last_exited->entity;
        if (player->owned) {
            can_interract = false;
        }
    });
    add_component(area_comp);
}

void Endgate::process(float delta) {
    sprite.update_transform(trans_comp);

    button_label.visible = can_interract;
    button_label.update_transform_cam(trans_comp);
}