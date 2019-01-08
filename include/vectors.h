#ifndef REFLECS_COMPONENTS_VECTORS_H
#define REFLECS_COMPONENTS_VECTORS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EcsVec2 {
    float x;
    float y;
} EcsVec2;

typedef struct EcsVec2Int {
    int x;
    int y;
} EcsVec2Int;

typedef struct EcsVec3 {
    float x;
    float y;
    float z;
} EcsVec3;

typedef struct EcsVec3Int {
    int x;
    int y;
    int z;
} EcsVec3Int;

typedef struct EcsVec4 {
    float w;
    float x;
    float y;
    float z;
} EcsVec4;

typedef struct EcsVec4Int {
    int w;
    int x;
    int y;
    int z;
} EcsVec4Int;


/* -- 2D vectors -- */

void ecs_vec2_set(
    EcsVec2 *vector,
    float x,
    float y);

void ecs_vec2_mult(
    EcsVec2 *vector,
    float m,
    EcsVec2 *vector_out);

void ecs_vec2_div(
    EcsVec2 *vector,
    float m, EcsVec2 *vector_out);

void ecs_vec2_add(
    EcsVec2 *vector_a,
    EcsVec2 *vector_b,
    EcsVec2 *vector_out);

void ecs_vec2_sub(
    EcsVec2 *vector_a,
    EcsVec2 *vector_b,
    EcsVec2 *vector_out);

void ecs_vec2_scale(EcsVec2 *vector_a, EcsVec2 *vector_b,
    EcsVec2 *vector_out);

void ecs_vec2_normalize(
    EcsVec2 *vector,
    EcsVec2 *vector_out);

void ecs_vec2_perpendicular(
    EcsVec2 *vector,
    EcsVec2 *vector_out);

void ecs_vec2_reflect(
    EcsVec2 *vector_a,
    EcsVec2 *vector_b,
    EcsVec2 *vector_out);

float ecs_vec2_cross(
    EcsVec2 *vector_a,
    EcsVec2 *vector_b);

float ecs_vec2_dot(
    EcsVec2 *vector_a,
    EcsVec2 *vector_b);

float ecs_vec2_magnitude(
    EcsVec2 *vector);

float ecs_vec2_magnitudeSqrt(
    EcsVec2 *vector);

float ecs_vec2_angle(
    EcsVec2 *vector);

float ecs_vec2_angle2(
    EcsVec2 *vector_a,
    EcsVec2 *vector_b);

float ecs_vec2_distance(
    EcsVec2 *vector_a,
    EcsVec2 *vector_b);

float ecs_vec2_distanceSqrt(
    EcsVec2 *vector_a,
    EcsVec2 *vector_b);


/* -- 3D vectors -- */

void ecs_vec3_set(
    EcsVec3 *vector,
    float x,
    float y,
    float z);

void ecs_vec3_mult(
    EcsVec3 *vector,
    float m,
    EcsVec3 *vector_out);

void ecs_vec3_div(
    EcsVec3 *vector,
    float m,
    EcsVec3 *vector_out);

void ecs_vec3_add(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b,
    EcsVec3 *vector_out);

void ecs_vec3_sub(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b,
    EcsVec3 *vector_out);

void ecs_vec3_scale(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b,
    EcsVec3 *vector_out);

void ecs_vec3_normalize(
    EcsVec3 *vector,
    EcsVec3 *vector_out);

void ecs_vec3_perpendicular(
    EcsVec3 *vector,
    EcsVec3 *vector_out);

void ecs_vec3_reflect(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b,
    EcsVec3 *vector_out);

void ecs_vec3_cross(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b,
    EcsVec3 *vector_out);

float ecs_vec3_dot(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b);

float ecs_vec3_magnitude(
    EcsVec3 *vector);

float ecs_vec3_magnitudeSqrt(
    EcsVec3 *vector);

float ecs_vec3_angle(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b);

float ecs_vec3_distance(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b);

float ecs_vec3_distanceSqrt(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b);

#undef DECLARE_METHODS

#ifdef __cplusplus
}
#endif

#endif
