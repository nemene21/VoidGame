#ifndef CHASER_H
#define CHASER_H
#include "../enemy.hpp"

class ChaserEnemy: public Enemy {
public:
    ChaserEnemy(Vector2 position);
    void chase(float delta);
    void process(float delta);
};
#endif