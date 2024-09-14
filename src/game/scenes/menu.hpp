#ifndef MENU_H
#define MENU_H
#include <scene.hpp>
#include <networking/networking.hpp>
#include <entities/UI/input_field/input_field.hpp>

class MenuScene: public Scene {
public:
    InputField* ip_input;

    MenuScene();
    void restart();
    void process(float delta);
};

#endif