#include "include/transform.h"
#include <string.h>
#include <math.h>

/* *************************************************** *
 *  Vector 2D
 * *************************************************** */
void ecs_vec2_set(
    EcsVec2 *vector,
    float x,
    float y)
{
    vector->x = x;
    vector->y = y;
}

void ecs_vec2_mult(
    EcsVec2 *vector,
    float m,
    EcsVec2 *vector_out)
{
    vector_out->x = vector->x*m;
    vector_out->y = vector->y*m;
}

void ecs_vec2_div(
    EcsVec2 *vector,
    float m,
    EcsVec2 *vector_out)
{
    vector_out->x = vector->x / m;
    vector_out->y = vector->y / m;
}

void ecs_vec2_add(
    EcsVec2 *vector_a,
    EcsVec2 *vector_b,
    EcsVec2 *vector_out)
{
    vector_out->x = vector_a->x + vector_b->x;
    vector_out->y = vector_a->y + vector_b->y;
}

void ecs_vec2_sub(
    EcsVec2 *vector_a,
    EcsVec2 *vector_b,
    EcsVec2 *vector_out)
{
    vector_out->x = vector_a->x - vector_b->x;
    vector_out->y = vector_a->y - vector_b->y;
}

void ecs_vec2_scale(
    EcsVec2 *vector_a,
    EcsVec2 *vector_b,
    EcsVec2 *vector_out)
{
    vector_out->x = vector_a->x * vector_b->x;
    vector_out->y = vector_a->y * vector_b->y;
}

void ecs_vec2_normalize(
    EcsVec2 *vector,
    EcsVec2 *vector_out)
{
    float magnitude = ecs_vec2_magnitude(vector);
    if (magnitude != 0) {
        vector_out->x = (vector->x/magnitude);
        vector_out->y = (vector->y/magnitude);
    } else {
        memcpy(vector_out, vector, sizeof(EcsVec2));
    }
}

void ecs_vec2_perpendicular(
    EcsVec2 *vector,
    EcsVec2 *vector_out)
{
    float x = vector->x;
    vector_out->x = -vector->y;
    vector_out->y = x;
}

void ecs_vec2_reflect(
    EcsVec2 *vector_a,
    EcsVec2 *vector_b,
    EcsVec2 *vector_out)
{
    EcsVec2 temp;
    ecs_vec2_mult(vector_b, 2 * ecs_vec2_dot(vector_a, vector_b), &temp);
    ecs_vec2_sub(vector_a, &temp, vector_out);
}

float ecs_vec2_cross(
    EcsVec2 *vector_a,
    EcsVec2 *vector_b)
{
    return vector_a->x*vector_b->y - vector_a->y*vector_b->x;
}

float ecs_vec2_dot(
    EcsVec2 *vector_a,
    EcsVec2 *vector_b)
{
    return vector_a->x * vector_b->x + vector_a->y * vector_b->y;
}

float ecs_vec2_magnitude(
    EcsVec2 *vector)
{
    return sqrtf(ecs_vec2_magnitudeSqrt(vector));
}

float ecs_vec2_magnitudeSqrt(
    EcsVec2 *vector)
{
    return ecs_vec2_dot(vector, vector);
}

float ecs_vec2_angle(
    EcsVec2 *vector)
{
    float angle = atan2f(vector->x, vector->y)*(180/M_PI);
    return angle < 0 ? angle + 360 : angle;
}

float ecs_vec2_angle2(
    EcsVec2 *vector_a,
    EcsVec2 *vector_b)
{
    float angle = ecs_vec2_angle(vector_a) - ecs_vec2_angle(vector_b);
    return angle < 0 ? angle + 360 : angle;
}

float ecs_vec2_distance(
    EcsVec2 *vector_a,
    EcsVec2 *vector_b)
{
    return sqrtf(ecs_vec2_distanceSqrt(vector_a, vector_b));
}

float ecs_vec2_distanceSqrt(
    EcsVec2 *vector_a,
    EcsVec2 *vector_b)
{
    float x = vector_a->x - vector_b->x;
    float y = vector_a->y - vector_b->y;
    return x*x+y*y;
}

/* *************************************************** *
 *  Vector 2D Int
 * *************************************************** */



/* *************************************************** *
 *  Vector 3D
 * *************************************************** */
void ecs_vec3_set(
    EcsVec3 *vector,
    float x,
    float y,
    float z)
{
    vector->x = x;
    vector->y = y;
    vector->z = z;
}

void ecs_vec3_mult(
    EcsVec3 *vector,
    float m,
    EcsVec3 *vector_out)
{
    vector_out->x = vector->x*m;
    vector_out->y = vector->y*m;
    vector_out->z = vector->z*m;
}

void ecs_vec3_div(
    EcsVec3 *vector,
    float m,
    EcsVec3 *vector_out)
{
    vector_out->x = vector->x/m;
    vector_out->y = vector->y/m;
    vector_out->z = vector->z/m;
}

void ecs_vec3_add(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b,
    EcsVec3 *vector_out)
{
    vector_out->x = vector_a->x + vector_b->x;
    vector_out->y = vector_a->y + vector_b->y;
    vector_out->z = vector_a->z + vector_b->z;
}

void ecs_vec3_sub(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b,
    EcsVec3 *vector_out)
{
    vector_out->x = vector_a->x - vector_b->x;
    vector_out->y = vector_a->y - vector_b->y;
    vector_out->z = vector_a->z - vector_b->z;
}

void ecs_vec3_scale(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b,
    EcsVec3 *vector_out)
{
    vector_out->x = vector_a->x * vector_b->x;
    vector_out->y = vector_a->y * vector_b->y;
    vector_out->z = vector_a->z * vector_b->z;
}

void ecs_vec3_normalize(
    EcsVec3 *vector,
    EcsVec3 *vector_out)
{
    float magnitude = ecs_vec3_magnitude(vector);
    if (magnitude != 0) {
        vector_out->x = vector->x / magnitude;
        vector_out->y = vector->y / magnitude;
        vector_out->z = vector->z / magnitude;
    } else {
        memcpy(vector_out, vector, sizeof(EcsVec3));
    }
}

void ecs_vec3_reflect(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b,
    EcsVec3 *vector_out)
{
    EcsVec3 temp;
    ecs_vec3_mult(vector_b, 2 * ecs_vec3_dot(vector_a, vector_b), &temp);
    ecs_vec3_sub(vector_a, &temp, vector_out);
}

void ecs_vec3_cross(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b,
    EcsVec3 *vector_out)
{
    float vector_a_x = vector_a->x;
    float vector_a_y = vector_b->y;
    float vector_b_x = vector_b->x;
    float vector_b_y = vector_b->y;

    vector_out->x = (vector_a->y * vector_b->z) - (vector_a->z * vector_b->y);
    vector_out->y = (vector_a->z * vector_b_x ) - (vector_a_x  * vector_b->z);
    vector_out->z = (vector_a_x  * vector_b_y ) - (vector_a_y  * vector_b_x );
}

float ecs_vec3_dot(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b)
{
    return (vector_a->x * vector_b->x +
            vector_a->y * vector_b->y +
            vector_a->z * vector_b->z);
}

float ecs_vec3_magnitude(
    EcsVec3 *vector)
{
    return sqrtf(ecs_vec3_magnitudeSqrt(vector));
}

float ecs_vec3_magnitudeSqrt(
    EcsVec3 *vector)
{
    return ecs_vec3_dot(vector, vector);
}

float ecs_vec3_angle(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b)
{
    float dot = ecs_vec3_dot(vector_a, vector_b);
    float m = sqrtf(ecs_vec3_magnitudeSqrt(vector_a) *
                  ecs_vec3_magnitudeSqrt(vector_b));
    return acos(dot/m);
}

float ecs_vec3_distance(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b)
{
    return sqrtf(ecs_vec3_distanceSqrt(vector_a, vector_b));
}

float ecs_vec3_distanceSqrt(
    EcsVec3 *vector_a,
    EcsVec3 *vector_b)
{
    float x = vector_a->x - vector_b->x;
    float y = vector_a->y - vector_b->y;
    float z = vector_a->z - vector_b->z;
    return x*x + y*y + z*z;
}
