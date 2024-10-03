#version 100
precision mediump float;

varying vec2 fragTexCoord;
uniform sampler2D texture0;
uniform float time;

uniform vec2 center;
uniform float hole_radius;
uniform float ring_radius;
uniform float halo_radius;

uniform float zoom;
uniform vec2 offset;

const float aspect_ratio = 320.0 / 180.0;

const float num_colors = 6.0;
const float rotation = 0.2;
const vec2 light_dir = vec2(1.0, 1.0);

const vec4 BLACK = vec4(0, 0, 0, 1);
const vec4 ORANGE = vec4(0.85, 0.53, 0.24, 1);
uniform sampler2D hole_colors;
uniform sampler2D noise;

float angle(vec2 v) {
    return atan(v.y, v.x);
}

vec3 lerp_col(vec3 first, vec3 other, float blend) {
    return first + (other - first) * blend;
}

vec2 rotate(vec2 v, float angle) {
    float cosA = cos(angle);
    float sinA = sin(angle);
    
    return vec2(
        v.x * cosA - v.y * sinA,
        v.x * sinA + v.y * cosA
    );
}

vec3 max_color(vec3 first, vec3 other) {
    return vec3(
        max(first.r, other.r),
        max(first.g, other.g),
        max(first.b, other.b)
    );
}

vec3 get_color(float anim) {
    anim /= 1.5;
    anim = floor(anim * num_colors) / num_colors;
    anim = max(anim, 0.01);
    anim = min(anim, 0.99);
    return texture2D(hole_colors, vec2(anim, 0.0)).rgb;
}

void main()
{
    vec2 uv = vec2(fragTexCoord.x, fragTexCoord.y);

    uv -= vec2(.5, .5);
    uv.x *= aspect_ratio;
    uv = rotate(uv, rotation);
    uv.x /= aspect_ratio;

    uv += offset;
    uv *= zoom;
    uv += vec2(.5, .5);

    uv += texture2D(noise, uv + time).rg * 0.01;
    uv.x *= aspect_ratio;

    vec2 diff = center - uv;
    float dist = length(diff);

    vec2 noise_sample_pos = vec2(angle(diff) / 3.14, time * 0.05);
    float noise_value = texture2D(noise, noise_sample_pos).r;

    float glow_sine = sin(time + 0.5) * 0.04;
    float animated_halo_radius = halo_radius + noise_value * 0.05;
    animated_halo_radius += glow_sine;

    float animated_ring_radius = ring_radius;
    animated_ring_radius += glow_sine;

    noise_value = pow(noise_value, 5.0) * 0.25;
    float animated_hole_radius = hole_radius + noise_value;
    animated_hole_radius += sin(time) * 0.03;

    float light = 1.3 + dot(light_dir, normalize(diff)) * 0.4;

    if (dist < animated_hole_radius) {
        gl_FragColor = BLACK;
        if (dist > hole_radius) {
            gl_FragColor.rgb = lerp_col(BLACK.rgb, vec3(0.1, 0.1, 0.2),
                pow((dist - hole_radius) / (animated_hole_radius - hole_radius), 0.75)
            );
        }
    }
    else if (dist < animated_halo_radius) {
        float anim = dist / animated_halo_radius;
        noise_value = texture2D(noise, vec2(angle(diff) / 3.14 + time * 0.075, anim)).r * 0.8 + 0.5;
        gl_FragColor.rgb = get_color(smoothstep(1.0, 0.65, anim) * light * noise_value);
    }
    float ring_dist = length(vec2(diff.x, diff.y * 4.0));

    bool in_ring = ring_dist < animated_ring_radius &&
                   ring_dist > animated_hole_radius &&
                   !(abs(diff.x) < animated_hole_radius && uv.y < 0.5);
    if (in_ring) {
        float anim = ring_dist / animated_ring_radius;
        noise_value = texture2D(noise, vec2(angle(diff) / 3.14 + time * 0.075, anim)).r * 0.7 + 0.3;
        gl_FragColor.rgb = max_color(
            gl_FragColor.rgb, get_color(smoothstep(1.0, 0.5, anim) * light * noise_value)
        );
    }

    if ((gl_FragColor.r + gl_FragColor.g + gl_FragColor.b) > 0.1) {
        gl_FragColor.a = 1.0;
    }
}