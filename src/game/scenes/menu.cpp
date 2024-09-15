#include "menu.hpp"

MenuScene::MenuScene():
    Scene("menu_scene") {}

void MenuScene::restart() {
    ip_input = new InputField({16, 16}, 20, "Ip address here", Networking::get_local_ip());
    add_entity(ip_input);
    name_input = new InputField({16, 64}, 20, "Name here", "Miroslav");
    add_entity(name_input);
}

void MenuScene::process(float delta) {
    if (IsKeyPressed(KEY_H)) {
        //Networking::host();
        //SceneManager::set_scene("game_scene");

    } else if (IsKeyPressed(KEY_J)) {
        //Networking::join(ip_input->text);
        //SceneManager::set_scene("game_scene");
    }
}