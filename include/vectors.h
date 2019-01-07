#ifndef REFLECS_COMPONENTS_VECTORS_H
#define REFLECS_COMPONENTS_VECTORS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EcsVector2D {
    float x;
    float y;
} EcsVector2D;

typedef struct EcsVector2DInt {
    int x;
    int y;
} EcsVector2DInt;

typedef struct EcsVector3D {
    float x;
    float y;
    float z;
} EcsVector3D;

typedef struct EcsVector3DInt {
    int x;
    int y;
    int z;
} EcsVector3DInt;

typedef struct EcsVector4D {
    float w;
    float x;
    float y;
    float z;
} EcsVector4D;

typedef struct EcsVector4DInt {
    int w;
    int x;
    int y;
    int z;
} EcsVector4DInt;

void EcsVector2D_set(EcsVector2D *vector, float x, float y);
void EcsVector2D_mult(EcsVector2D *vector, float m, EcsVector2D *vector_out);
void EcsVector2D_div(EcsVector2D *vector, float m, EcsVector2D *vector_out);
void EcsVector2D_add(EcsVector2D *vector_a, EcsVector2D *vector_b, EcsVector2D *vector_out);
void EcsVector2D_sub(EcsVector2D *vector_a, EcsVector2D *vector_b, EcsVector2D *vector_out);
void EcsVector2D_scale(EcsVector2D *vector_a, EcsVector2D *vector_b, EcsVector2D *vector_out);
void EcsVector2D_normalize(EcsVector2D *vector, EcsVector2D *vector_out);
void EcsVector2D_perpendicular(EcsVector2D *vector, EcsVector2D *vector_out);
void EcsVector2D_reflect(EcsVector2D *vector_a, EcsVector2D *vector_b, EcsVector2D *vector_out);
float EcsVector2D_cross(EcsVector2D *vector_a, EcsVector2D *vector_b);
float EcsVector2D_dot(EcsVector2D *vector_a, EcsVector2D *vector_b);
float EcsVector2D_magnitude(EcsVector2D *vector);
float EcsVector2D_magnitudeSqrt(EcsVector2D *vector);
float EcsVector2D_angle(EcsVector2D *vector);
float EcsVector2D_angle2(EcsVector2D *vector_a, EcsVector2D *vector_b);
float EcsVector2D_distance(EcsVector2D *vector_a, EcsVector2D *vector_b);
float EcsVector2D_distanceSqrt(EcsVector2D *vector_a, EcsVector2D *vector_b);

void EcsVector3D_set(EcsVector3D *vector, float x, float y, float z);
void EcsVector3D_mult(EcsVector3D *vector, float m, EcsVector3D *vector_out);
void EcsVector3D_div(EcsVector3D *vector, float m, EcsVector3D *vector_out);
void EcsVector3D_add(EcsVector3D *vector_a, EcsVector3D *vector_b, EcsVector3D *vector_out);
void EcsVector3D_sub(EcsVector3D *vector_a, EcsVector3D *vector_b, EcsVector3D *vector_out);
void EcsVector3D_scale(EcsVector3D *vector_a, EcsVector3D *vector_b, EcsVector3D *vector_out);
void EcsVector3D_normalize(EcsVector3D *vector, EcsVector3D *vector_out);
void EcsVector3D_perpendicular(EcsVector3D *vector, EcsVector3D *vector_out);
void EcsVector3D_reflect(EcsVector3D *vector_a, EcsVector3D *vector_b, EcsVector3D *vector_out);
void EcsVector3D_cross(EcsVector3D *vector_a, EcsVector3D *vector_b, EcsVector3D *vector_out);
float EcsVector3D_dot(EcsVector3D *vector_a, EcsVector3D *vector_b);
float EcsVector3D_magnitude(EcsVector3D *vector);
float EcsVector3D_magnitudeSqrt(EcsVector3D *vector);
float EcsVector3D_angle(EcsVector3D *vector_a, EcsVector3D *vector_b);
float EcsVector3D_distance(EcsVector3D *vector_a, EcsVector3D *vector_b);
float EcsVector3D_distanceSqrt(EcsVector3D *vector_a, EcsVector3D *vector_b);

#undef DECLARE_METHODS

#ifdef __cplusplus
}
#endif

#endif
