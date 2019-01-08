#include <reflecs.components.transform>
#include <math.h>

#define MATRIX_GET(matrix, x, y) ((*matrix)[x][y])

void ecs_mat3x3_add_rotation(
    EcsMat3x3 *matrix,
    float rad)
{
    float c = cos(rad);
    float s = sin(rad);
    matrix->data[0][0] = c;
    matrix->data[0][1] = -s;
    matrix->data[1][0] = s;
    matrix->data[1][1] = c;
}

void ecs_mat3x3_add_translation(
    EcsMat3x3 *matrix,
    EcsVec2 *translation)
{
    matrix->data[0][2] += translation->x;
    matrix->data[1][2] += translation->y;
}

void ecs_mat3x3_transform(
    EcsMat3x3 *matrix,
    EcsVec2 *src,
    EcsVec2 *dest,
    size_t size)
{
    for (size_t i = 0; i < size; i++) {
        float x = src[i].x;
        float y = src[i].y;
        dest[i].x = matrix->data[0][0] * x +
                    matrix->data[0][1] * y +
                    matrix->data[0][2];
        dest[i].y = matrix->data[1][0] * x +
                    matrix->data[1][1] * y +
                    matrix->data[1][2];
    }
}

void ecs_mat3x3_transform_int(
    EcsMat3x3 *matrix,
    EcsVec2Int *src,
    EcsVec2Int *dest,
    size_t size)
{
    for (size_t i = 0; i < size; i++) {
        float x = src[i].x;
        float y = src[i].y;

        dest[i].x = matrix->data[0][0] * x +
                    matrix->data[0][1] * y +
                    matrix->data[0][2];
        dest[i].y = matrix->data[1][0] * x +
                    matrix->data[1][1] * y +
                    matrix->data[1][2];
    }
}
