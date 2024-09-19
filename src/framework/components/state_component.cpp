#include <state_component.hpp>
#include <entity.hpp>

StateComponent::StateComponent(Entity* entity, StateMap states, std::string state):
    Component(CompType::STATE_MACHINE, entity),
    states {states},
    state {state},
    paused {false} {}

void StateComponent::process(float delta) {
    if (paused || !entity->owned)
        return;
    
    states[state](delta);
}

void StateComponent::pause() {
    paused = true;
}
void StateComponent::unpause() {
    paused = false;
}
void StateComponent::toggle_paused() {
    paused = !paused;
}
void StateComponent::set_paused(bool new_paused) {
    paused = new_paused;
}

void StateComponent::set_state(std::string new_state) {
    if (states.find(new_state) == states.end())
        std::cerr << new_state << " is not a valid state!" << std::endl;

    state = new_state;
}
