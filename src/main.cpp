#include <framework.hpp>
#include <scenes/game.hpp>
#include <scenes/menu.hpp>

int main() {
    Framework::init("Void Game", {320, 180}, 2, true);

    new GameScene();
    new MenuScene();
    SceneManager::set_scene("menu_scene");

    Framework::run();
    return 0;
}