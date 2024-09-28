#include "background.hpp"

Background::Background(): sprite {Sprite("blank.png")} {
    sprite.z_coord = -100;
    auto& bond = sprite.shader_bond;
    bond.set_shader("background.glsl");

    add_component(new TransformComponent(this));
    set_name("Background");
}

void Background::process(float delta) {
    auto cam = CameraManager::get_camera();
    sprite.update_transform((TransformComponent*)get_component(CompType::TRANSFORM));
    sprite.position += cam->target - cam->offset + half_res;

    auto& bond = sprite.shader_bond;
    Vector2 center = {(320.f/180.f) * .5f, .5};
    bond.send_uniform("center", &center, sizeof(center), SHADER_UNIFORM_VEC2);
    float radius = 0.3;
    bond.send_uniform("hole_radius", &radius, sizeof(radius), SHADER_UNIFORM_FLOAT);
    radius = 0.45;
    bond.send_uniform("halo_radius", &radius, sizeof(radius), SHADER_UNIFORM_FLOAT);
    radius = 0.85;
    bond.send_uniform("ring_radius", &radius, sizeof(radius), SHADER_UNIFORM_FLOAT);

    float zoom = 2;
    bond.send_uniform("zoom", &zoom, sizeof(zoom), SHADER_UNIFORM_FLOAT);

    Vector2 offset = {0.25, 0.25};
    bond.send_uniform("offset", &offset, sizeof(offset), SHADER_UNIFORM_VEC2);

    bond.bind_texture("noise", TextureManager::get("noise.png"));
}
