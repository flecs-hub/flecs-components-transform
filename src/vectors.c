#include "include/transform.h"
#include <string.h>
#include <math.h>

/* *************************************************** *
 *  Vector 2D
 * *************************************************** */
void EcsVector2D_set(
    EcsVector2D *vector,
    float x,
    float y)
{
    vector->x = x;
    vector->y = y;
}

void EcsVector2D_mult(
    EcsVector2D *vector,
    float m,
    EcsVector2D *vector_out)
{
    vector_out->x = vector->x*m;
    vector_out->y = vector->y*m;
}

void EcsVector2D_div(
    EcsVector2D *vector,
    float m,
    EcsVector2D *vector_out)
{
    vector_out->x = vector->x / m;
    vector_out->y = vector->y / m;
}

void EcsVector2D_add(
    EcsVector2D *vector_a,
    EcsVector2D *vector_b,
    EcsVector2D *vector_out)
{
    vector_out->x = vector_a->x + vector_b->x;
    vector_out->y = vector_a->y + vector_b->y;
}

void EcsVector2D_sub(
    EcsVector2D *vector_a,
    EcsVector2D *vector_b,
    EcsVector2D *vector_out)
{
    vector_out->x = vector_a->x - vector_b->x;
    vector_out->y = vector_a->y - vector_b->y;
}

void EcsVector2D_scale(
    EcsVector2D *vector_a,
    EcsVector2D *vector_b,
    EcsVector2D *vector_out)
{
    vector_out->x = vector_a->x * vector_b->x;
    vector_out->y = vector_a->y * vector_b->y;
}

void EcsVector2D_normalize(
    EcsVector2D *vector,
    EcsVector2D *vector_out)
{
    float magnitude = EcsVector2D_magnitude(vector);
    if (magnitude != 0) {
        vector_out->x = (vector->x/magnitude);
        vector_out->y = (vector->y/magnitude);
    } else {
        memcpy(vector_out, vector, sizeof(EcsVector2D));
    }
}

void EcsVector2D_perpendicular(
    EcsVector2D *vector,
    EcsVector2D *vector_out)
{
    float x = vector->x;
    vector_out->x = -vector->y;
    vector_out->y = x;
}

void EcsVector2D_reflect(
    EcsVector2D *vector_a,
    EcsVector2D *vector_b,
    EcsVector2D *vector_out)
{
    EcsVector2D temp;
    EcsVector2D_mult(vector_b, 2 * EcsVector2D_dot(vector_a, vector_b), &temp);
    EcsVector2D_sub(vector_a, &temp, vector_out);
}

float EcsVector2D_cross(
    EcsVector2D *vector_a,
    EcsVector2D *vector_b)
{
    return vector_a->x*vector_b->y - vector_a->y*vector_b->x;
}

float EcsVector2D_dot(
    EcsVector2D *vector_a,
    EcsVector2D *vector_b)
{
    return vector_a->x * vector_b->x + vector_a->y * vector_b->y;
}

float EcsVector2D_magnitude(
    EcsVector2D *vector)
{
    return sqrtf(EcsVector2D_magnitudeSqrt(vector));
}

float EcsVector2D_magnitudeSqrt(
    EcsVector2D *vector)
{
    return EcsVector2D_dot(vector, vector);
}

float EcsVector2D_angle(
    EcsVector2D *vector)
{
    float angle = atan2f(vector->x, vector->y)*(180/M_PI);
    return angle < 0 ? angle + 360 : angle;
}

float EcsVector2D_angle2(
    EcsVector2D *vector_a,
    EcsVector2D *vector_b)
{
    float angle = EcsVector2D_angle(vector_a) - EcsVector2D_angle(vector_b);
    return angle < 0 ? angle + 360 : angle;
}

float EcsVector2D_distance(
    EcsVector2D *vector_a,
    EcsVector2D *vector_b)
{
    return sqrtf(EcsVector2D_distanceSqrt(vector_a, vector_b));
}

float EcsVector2D_distanceSqrt(
    EcsVector2D *vector_a,
    EcsVector2D *vector_b)
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
void EcsVector3D_set(
    EcsVector3D *vector,
    float x,
    float y,
    float z)
{
    vector->x = x;
    vector->y = y;
    vector->z = z;
}

void EcsVector3D_mult(
    EcsVector3D *vector,
    float m,
    EcsVector3D *vector_out)
{
    vector_out->x = vector->x*m;
    vector_out->y = vector->y*m;
    vector_out->z = vector->z*m;
}

void EcsVector3D_div(
    EcsVector3D *vector,
    float m,
    EcsVector3D *vector_out)
{
    vector_out->x = vector->x/m;
    vector_out->y = vector->y/m;
    vector_out->z = vector->z/m;
}

void EcsVector3D_add(
    EcsVector3D *vector_a,
    EcsVector3D *vector_b,
    EcsVector3D *vector_out)
{
    vector_out->x = vector_a->x + vector_b->x;
    vector_out->y = vector_a->y + vector_b->y;
    vector_out->z = vector_a->z + vector_b->z;
}

void EcsVector3D_sub(
    EcsVector3D *vector_a,
    EcsVector3D *vector_b,
    EcsVector3D *vector_out)
{
    vector_out->x = vector_a->x - vector_b->x;
    vector_out->y = vector_a->y - vector_b->y;
    vector_out->z = vector_a->z - vector_b->z;
}

void EcsVector3D_scale(
    EcsVector3D *vector_a,
    EcsVector3D *vector_b,
    EcsVector3D *vector_out)
{
    vector_out->x = vector_a->x * vector_b->x;
    vector_out->y = vector_a->y * vector_b->y;
    vector_out->z = vector_a->z * vector_b->z;
}

void EcsVector3D_normalize(
    EcsVector3D *vector,
    EcsVector3D *vector_out)
{
    float magnitude = EcsVector3D_magnitude(vector);
    if (magnitude != 0) {
        vector_out->x = vector->x / magnitude;
        vector_out->y = vector->y / magnitude;
        vector_out->z = vector->z / magnitude;
    } else {
        memcpy(vector_out, vector, sizeof(EcsVector3D));
    }
}

void EcsVector3D_reflect(
    EcsVector3D *vector_a,
    EcsVector3D *vector_b,
    EcsVector3D *vector_out)
{
    EcsVector3D temp;
    EcsVector3D_mult(vector_b, 2 * EcsVector3D_dot(vector_a, vector_b), &temp);
    EcsVector3D_sub(vector_a, &temp, vector_out);
}

void EcsVector3D_cross(
    EcsVector3D *vector_a,
    EcsVector3D *vector_b,
    EcsVector3D *vector_out)
{
    float vector_a_x = vector_a->x;
    float vector_a_y = vector_b->y;
    float vector_b_x = vector_b->x;
    float vector_b_y = vector_b->y;

    vector_out->x = (vector_a->y * vector_b->z) - (vector_a->z * vector_b->y);
    vector_out->y = (vector_a->z * vector_b_x ) - (vector_a_x  * vector_b->z);
    vector_out->z = (vector_a_x  * vector_b_y ) - (vector_a_y  * vector_b_x );
}

float EcsVector3D_dot(
    EcsVector3D *vector_a,
    EcsVector3D *vector_b)
{
    return (vector_a->x * vector_b->x +
            vector_a->y * vector_b->y +
            vector_a->z * vector_b->z);
}

float EcsVector3D_magnitude(
    EcsVector3D *vector)
{
    return sqrtf(EcsVector3D_magnitudeSqrt(vector));
}

float EcsVector3D_magnitudeSqrt(
    EcsVector3D *vector)
{
    return EcsVector3D_dot(vector, vector);
}

float EcsVector3D_angle(
    EcsVector3D *vector_a,
    EcsVector3D *vector_b)
{
    float dot = EcsVector3D_dot(vector_a, vector_b);
    float m = sqrtf(EcsVector3D_magnitudeSqrt(vector_a) *
                  EcsVector3D_magnitudeSqrt(vector_b));
    return acos(dot/m);
}

float EcsVector3D_distance(
    EcsVector3D *vector_a,
    EcsVector3D *vector_b)
{
    return sqrtf(EcsVector3D_distanceSqrt(vector_a, vector_b));
}

float EcsVector3D_distanceSqrt(
    EcsVector3D *vector_a,
    EcsVector3D *vector_b)
{
    float x = vector_a->x - vector_b->x;
    float y = vector_a->y - vector_b->y;
    float z = vector_a->z - vector_b->z;
    return x*x + y*y + z*z;
}
