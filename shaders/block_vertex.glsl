#version 120

uniform mat4 matrix;
uniform vec3 camera;
uniform float fog_distance;
uniform int ortho;
uniform mat4 translation;

attribute vec4 position;
attribute vec3 normal;
attribute vec4 uv;

varying vec2 fragment_uv;
varying float fragment_ao;
varying float fragment_light;
varying float fog_factor;
varying float fog_height;
varying float diffuse;

const float pi = 3.14159265;
const vec3 light_direction = normalize(vec3(-1.0, 1.0, -1.0));

void main() {
    vec4 global_position = translation * position;
    gl_Position = matrix * global_position;
    fragment_uv = uv.xy;
    fragment_ao = 0.3 + (1.0 - uv.z) * 0.7;
    fragment_light = uv.w;
    diffuse = max(0.0, dot(normal, light_direction));
    if (bool(ortho)) {
        fog_factor = 0.0;
        fog_height = 0.0;
    }
    else {
        float camera_distance = distance(camera, vec3(global_position));
        fog_factor = pow(clamp(camera_distance / fog_distance, 0.0, 1.0), 4.0);
        float dy = global_position.y - camera.y;
        float dx = distance(global_position.xz, camera.xz);
        fog_height = (atan(dy, dx) + pi / 2) / pi;
    }
}
