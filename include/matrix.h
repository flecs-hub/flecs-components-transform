#ifndef REFLECS_COMPONENTS_MATRIX_H
#define REFLECS_COMPONENTS_MATRIX_H

#include <reflecs/reflecs.h>
#include <reflecs/components/transform/vectors.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EcsMatrix3x3 {
    float data[3][3];
} EcsMatrix3x3;

#define EcsMatrix3x3_Identity() {{{1,0,0},{0,1,0},{0,0,0}}}

void EcsMatrix3x3_add_rotation(EcsMatrix3x3 *matrix, float rad);
void EcsMatrix3x3_add_translation(EcsMatrix3x3 *matrix, EcsVector2D *translation);
void EcsMatrix3x3_transform(EcsMatrix3x3 *matrix, EcsVector2D *src, EcsVector2D *dest, size_t size);

#ifdef __cplusplus
}
#endif

#endif
