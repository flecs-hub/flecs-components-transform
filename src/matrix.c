#include <reflecs.components.transform>
#include <math.h>

#define MATRIX_GET(matrix, x, y) ((*matrix)[x][y])

void EcsMatrix3x3_add_rotation(
    EcsMatrix3x3 *matrix,
    float rad)
{
    float c = cos(rad);
    float s = sin(rad);
    matrix->data[0][0] = c;
    matrix->data[0][1] = -s;
    matrix->data[1][0] = s;
    matrix->data[1][1] = c;
}

void EcsMatrix3x3_add_translation(
    EcsMatrix3x3 *matrix,
    EcsVector2D *translation)
{
    matrix->data[0][2] += translation->x;
    matrix->data[1][2] += translation->y;
}

void EcsMatrix3x3_transform(
    EcsMatrix3x3 *matrix,
    EcsVector2D *src,
    EcsVector2D *dest,
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
