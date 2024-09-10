#ifndef STATE_H
#define STATE_H
#include <component.hpp>
#include <functional>

typedef std::map<std::string, std::function<void(float)>> StateMap;

class StateComponent: public Component {
public:
    StateMap states;
    std::string state;
    bool paused;

    void pause();
    void unpause();
    void toggle_paused();
    void set_paused(bool new_paused);

    StateComponent(Entity* entity, StateMap states, std::string state);

    void process(float delta);
    void set_state(std::string new_state);
};

#endif