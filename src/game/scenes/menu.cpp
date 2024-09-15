#include "menu.hpp"

MenuScene::MenuScene():
    Scene("menu_scene") {}

void MenuScene::restart() {
    ip_input = new InputField({16, 16}, 20, "Ip address here", Networking::get_local_ip());
    add_entity(ip_input);

    name_input = new InputField({16, 16+32}, 20, "Name here", "Miroslav");
    add_entity(name_input);

    host_button = new Button({16, 16+64}, "Host");
    host_button->on_press.connect([this](Entity* ent) {
        Networking::host();
        SceneManager::set_scene("game_scene");
    });
    add_entity(host_button);

    join_button = new Button({16, 16 + 96}, "Join");
    join_button->on_press.connect([this](Entity* ent) {
        Networking::join(ip_input->text);
        SceneManager::set_scene("game_scene");
    });
    add_entity(join_button);
}

void MenuScene::process(float delta) {

}