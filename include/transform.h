#ifndef REFLECS_COMPONENTS_TRANSFORM_H
#define REFLECS_COMPONENTS_TRANSFORM_H

#include <reflecs/reflecs.h>

#ifdef __cplusplus
extern "C" {
#endif

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
    float angle;
} EcsRotation2D;

typedef EcsVector3D EcsRotation3D;

typedef EcsVector4D EcsQuaternion;

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
