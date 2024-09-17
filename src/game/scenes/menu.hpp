#ifndef MENU_H
#define MENU_H
#include <scene.hpp>
#include <networking/networking.hpp>
#include <entities/UI/input_field/input_field.hpp>
#include <entities/UI/button/button.hpp>

class MenuScene: public Scene {
public:
    InputField* ip_input;
    InputField* name_input;
    Button* host_button;
    Button* join_button;

    MenuScene();
    void restart();
    void process(float delta);
};

#endif