#include "game_start_ui.hpp"

GameStartUI::GameStartUI():
    start_label {Label({16, 16}, "Waiting for host to start...", 22)}
    {
        set_name("Start UI");
    }

void GameStartUI::process(float delta) {
    if (Networking::is_host) {
        start_label.text = "[s] to start, players: " + std::to_string(
            Networking::get_user_count()+1
        );
    }
}