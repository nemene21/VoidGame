#include "endgate.hpp"
#include <scenes/game.hpp>

Endgate::Endgate(Vector2 pos): sprite {Sprite("next_level.png")},
    button_label {Label(pos, "E", 16, {.5, .5})},
    can_interact {false} {
    trans_comp = new TransformComponent(this, pos);

    button_label.offset = {0, -8.0};

    if (!Networking::is_host) return;
    area_comp = new AreaComponent(this, 24);
    area_comp->position = pos;
    area_comp->add_mask_bit((int)AreaIndex::PLAYER_HURTBOX);
    area_comp->area_entered.connect([this](Entity* ent) {
        auto player = area_comp->last_entered->entity;
        if (player->owned) {
            can_interact = true;
        }
    });
    area_comp->area_exited.connect([this](Entity* ent) {
        auto player = area_comp->last_exited->entity;
        if (player->owned) {
            can_interact = false;
        }
    });
    add_component(area_comp);
}

void Endgate::process(float delta) {
    sprite.update_transform(trans_comp);

    button_label.visible = can_interact;
    button_label.update_transform_cam(trans_comp);

    if (can_interact && IsJustPressed("Interact")) {
        SceneManager::set_scene_global("game_scene");
        auto scene = (GameScene*)SceneManager::scene_on;
    }
}