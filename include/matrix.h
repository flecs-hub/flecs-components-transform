#ifndef REFLECS_COMPONENTS_MATRIX_H
#define REFLECS_COMPONENTS_MATRIX_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EcsMat3x3 {
    float data[3][3];
} EcsMat3x3;

#define ECS_MAT3X3_IDENTITY (EcsMat3x3){{{1,0,0},{0,1,0},{0,0,0}}}

void ecs_mat3x3_add_rotation(
    EcsMat3x3 *matrix,
    float rad);

void ecs_mat3x3_add_translation(
    EcsMat3x3 *matrix,
    EcsVec2 *translation);

void ecs_mat3x3_add_scale(
    EcsMat3x3 *matrix,
    EcsVec2 *scale);

void ecs_mat3x3_transform(
    EcsMat3x3 *matrix,
    EcsVec2 *src,
    EcsVec2 *dest,
    size_t size);

void ecs_mat3x3_transform_int(
    EcsMat3x3 *matrix,
    EcsVec2Int *src,
    EcsVec2Int *dest,
    size_t size);

#ifdef __cplusplus
}
#endif

#endif
