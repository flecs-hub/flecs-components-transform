#ifndef REFLECS_COMPONENTS_TRANSFORM_H
#define REFLECS_COMPONENTS_TRANSFORM_H

#include "bake_config.h"
#include "vectors.h"
#include "matrix.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef EcsVec2 EcsPosition2D;

typedef EcsVec3 EcsPosition3D;

typedef EcsVec2 EcsScale2D;

typedef EcsVec3 EcsScale3D;

typedef struct EcsRotation2D {
    float angle;
} EcsRotation2D;

typedef EcsVec3 EcsRotation3D;

typedef EcsVec4 EcsQuaternion;

typedef struct EcsComponentsTransformHandles {
    EcsHandle Position2D;
    EcsHandle Position3D;
    EcsHandle Scale2D;
    EcsHandle Scale3D;
    EcsHandle Rotation2D;
    EcsHandle Rotation3D;
    EcsHandle Quaternion;
} EcsComponentsTransformHandles;

void EcsComponentsTransform(
    EcsWorld *world,
    int flags,
    void *handles_out);

#define DeclareHandle(handles, component)\
    EcsHandle Ecs##component##_h = handles.component; (void)Ecs##component##_h

#define EcsComponentsTransform_DeclareHandles(handles)\
    EcsDeclareHandle(handles, Position2D);\
    EcsDeclareHandle(handles, Position3D);\
    EcsDeclareHandle(handles, Scale2D);\
    EcsDeclareHandle(handles, Scale3D);\
    EcsDeclareHandle(handles, Rotation2D);\
    EcsDeclareHandle(handles, Rotation3D);

#undef DeclareHandle

#ifdef __cplusplus
}
#endif

#endif
