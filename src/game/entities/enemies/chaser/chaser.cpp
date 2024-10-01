#include "chaser.hpp"
#include <scene.hpp>
const float CHASER_SPEED = 100;

ChaserEnemy::ChaserEnemy(Vector2 position):
    Enemy(new StateComponent(this, {
        {"chase", [this](float delta) { chase(delta); }}
    }, "chase"), 100, "test_enemy.png", position, 8)
    {
        type = EntityType::CHASER_ENEMY;
        
        collider_comp = new ColliderComponent(this, position, 8, 8);
        collider_comp->add_mask_bit((int)ColliderIndex::TILEMAP);
        add_component(collider_comp);
    }

void ChaserEnemy::process(float delta) {
    Enemy::process(delta);
    sprite.update_transform(trans_comp);
}


void ChaserEnemy::chase(float delta) {
    std::cout << "only host should process this!" << std::endl;
    auto tilemap = (Tilemap*)SceneManager::scene_on->get_entity("Tilemap");

    auto target_trans = (TransformComponent*)target->get_component(CompType::TRANSFORM);
    auto optimal_vel = tilemap->pathfind(trans_comp->position, target_trans->position);
    optimal_vel = Vector2Normalize(optimal_vel);
    optimal_vel *= CHASER_SPEED;

    trans_comp->interpolate_velocity(optimal_vel, 10);
}
