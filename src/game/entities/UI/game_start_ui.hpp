#ifndef GAME_START_H
#define GAME_START_H
#include <entity.hpp>
#include <label.hpp>

class GameStartUI: public Entity {
public:
    Label start_label;
    GameStartUI();

    void process(float delta);
};

#endif