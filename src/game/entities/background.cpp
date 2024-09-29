#include "background.hpp"

Background::Background():
    hole_sprite {Sprite("black_hole/blank.png")},
    star_sprite {Sprite("black_hole/stars.png")} {
    hole_sprite.z_coord = -100;
    star_sprite.z_coord = hole_sprite.z_coord - 1;

    auto& bond = hole_sprite.shader_bond;
    bond.set_shader("hole.glsl");
    star_sprite.shader_bond.set_shader("stars.glsl");

    add_component(new TransformComponent(this));
    set_name("Background");

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

    bond.bind_texture("noise", TextureManager::get("black_hole/noise.png"));
    bond.bind_texture("hole_colors", TextureManager::get("black_hole/hole_gradient.png"));

}

void Background::process(float delta) {
    auto cam = CameraManager::get_camera();
    hole_sprite.update_transform((TransformComponent*)get_component(CompType::TRANSFORM));
    hole_sprite.position += cam->target - cam->offset + half_res;

    star_sprite.update_transform((TransformComponent*)get_component(CompType::TRANSFORM));
    star_sprite.position += cam->target - cam->offset + half_res;
}
