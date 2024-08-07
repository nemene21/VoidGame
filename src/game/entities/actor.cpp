#include "actor.hpp"

Actor::Actor(std::string texture, Vector2 position, float health):
    sprite {Sprite(texture)},
    trans_comp  {new TransformComponent(this, position)},
    health_comp {new HealthComponent(this, health)}
    {
    add_component(trans_comp);

    // Kills actor on death
    health_comp->died_signal.connect([this](Entity* entity) {
        queue_free();
    });
}