#ifndef REFLECS_COMPONENTS_TRANSFORM_H
#define REFLECS_COMPONENTS_TRANSFORM_H

#include <reflecs/reflecs.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ECS_2D (1)
#define ECS_3D (2)

typedef struct EcsVector2D {
    float x;
    float y;
} EcsVector2D;

typedef struct EcsVector3D {
    float x;
    float y;
    float z;
} EcsVector3D;

typedef struct EcsVector4D {
    float w;
    float x;
    float y;
    float z;
} EcsVector4D;

typedef EcsVector2D EcsPosition2D;

typedef EcsVector3D EcsPosition3D;

typedef EcsVector2D EcsScale2D;

typedef EcsVector3D EcsScale3D;

typedef struct EcsRotation2D {
    float value;
} EcsRotation2D;

typedef EcsVector3D EcsRotation3D;

typedef EcsVector4D EcsQuaternion;

typedef struct EcsComponentTransformHandles {
    EcsHandle Position2D;
    EcsHandle Position3D;
    EcsHandle Scale2D;
    EcsHandle Scale3D;
    EcsHandle Rotation2D;
    EcsHandle Rotation3D;
    EcsHandle Quaternion;
} EcsComponentTransformHandles;

void EcsComponentsTransform(
    EcsWorld *world,
    int flags,
    void *handles_out);

#ifdef __cplusplus
}
#endif

#endif
