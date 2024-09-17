#include "focusable.hpp"

Focusable::Focusable(Vector2 pos): focused {false} {
    trans_comp = new TransformComponent(this, pos);
    join_group("FOCUSABLE");
}

void Focusable::focus_on_rect(Vector2 dim, Vector2 centering) {
    bool LE = mouse_pos().x > trans_comp->position.x - dim.x * centering.x;
    bool RI = mouse_pos().x < trans_comp->position.x + dim.x * (1.f - centering.x);
    bool UP = mouse_pos().y > trans_comp->position.y - dim.y * centering.y;
    bool DW = mouse_pos().y < trans_comp->position.y + dim.y * (1.f - centering.y);

    bool clicked = IsJustPressed("Click");
    if (LE && RI && UP && DW && clicked) {
        focus();
    } else if (clicked) {
        unfocus();
    }
}

void Focusable::focus() {
    auto ents = SceneManager::scene_on->query_in_group("FOCUSABLE");
    on_focus.emit(this);

    for (auto ent: ents) {
        ((Focusable*)ent)->focused = false;
    }
    focused = true;
}

void Focusable::unfocus() {
    focused = false;
    on_unfocus.emit(this);
}