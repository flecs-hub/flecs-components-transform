#ifndef REFLECS_COMPONENTS_TRANSFORM_H
#define REFLECS_COMPONENTS_TRANSFORM_H

#include "bake_config.h"

#ifndef M_PI
#define M_PI	3.1415926535897932384626433832795
#endif

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

typedef EcsMat3x3 EcsMatTransform2D;

typedef EcsMat3x3 EcsMatProject2D;

typedef struct EcsComponentsTransformHandles {
    EcsEntity Position2D;
    EcsEntity Position3D;
    EcsEntity Scale2D;
    EcsEntity Scale3D;
    EcsEntity Rotation2D;
    EcsEntity Rotation3D;
    EcsEntity MatTransform2D;
    EcsEntity MatProject2D;
} EcsComponentsTransformHandles;

void EcsComponentsTransform(
    EcsWorld *world,
    int flags,
    void *handles_out);

#define DeclareHandle(handles, component)\
    EcsEntity Ecs##component##_h = handles.component; (void)Ecs##component##_h

#define EcsComponentsTransform_DeclareHandles(handles)\
    EcsDeclareHandle(handles, Position2D);\
    EcsDeclareHandle(handles, Position3D);\
    EcsDeclareHandle(handles, Scale2D);\
    EcsDeclareHandle(handles, Scale3D);\
    EcsDeclareHandle(handles, Rotation2D);\
    EcsDeclareHandle(handles, Rotation3D);\
    EcsDeclareHandle(handles, MatTransform2D);\
    EcsDeclareHandle(handles, MatProject2D);

#undef DeclareHandle

#ifdef __cplusplus
}
#endif

#endif
