#include "chaser.hpp"
const float CHASER_SPEED = 100;

ChaserEnemy::ChaserEnemy(Vector2 position):
    Enemy(new StateComponent(this, {
        {"chase", [this](float delta) { chase(delta); }}
    }, "chase"), 100, "test_enemy.png", position, 8)
    {
        type = EntityType::CHASER_ENEMY;
    }

void ChaserEnemy::process(float delta) {
    sprite.update_transform(trans_comp);
}


void ChaserEnemy::chase(float delta) {
    auto target_trans = (TransformComponent*)target->get_component(CompType::TRANSFORM);
    auto optimal_vel = target_trans->position - trans_comp->position;
    optimal_vel = Vector2Normalize(optimal_vel);
    optimal_vel *= CHASER_SPEED;

    trans_comp->interpolate_velocity(optimal_vel, 10);
}
