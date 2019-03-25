#ifndef FLECS_COMPONENTS_TRANSFORM_H
#define FLECS_COMPONENTS_TRANSFORM_H

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
    ECS_DECLARE_COMPONENT(EcsPosition2D);
    ECS_DECLARE_COMPONENT(EcsPosition3D);
    ECS_DECLARE_COMPONENT(EcsScale2D);
    ECS_DECLARE_COMPONENT(EcsScale3D);
    ECS_DECLARE_COMPONENT(EcsRotation2D);
    ECS_DECLARE_COMPONENT(EcsRotation3D);
    ECS_DECLARE_COMPONENT(EcsMatTransform2D);
    ECS_DECLARE_COMPONENT(EcsMatProject2D);
} EcsComponentsTransformHandles;

void EcsComponentsTransform(
    ecs_world_t *world,
    int flags,
    void *handles_out);

#define EcsComponentsTransform_ImportHandles(handles)\
    ECS_IMPORT_COMPONENT(handles, EcsPosition2D);\
    ECS_IMPORT_COMPONENT(handles, EcsPosition3D);\
    ECS_IMPORT_COMPONENT(handles, EcsScale2D);\
    ECS_IMPORT_COMPONENT(handles, EcsScale3D);\
    ECS_IMPORT_COMPONENT(handles, EcsRotation2D);\
    ECS_IMPORT_COMPONENT(handles, EcsRotation3D);\
    ECS_IMPORT_COMPONENT(handles, EcsMatTransform2D);\
    ECS_IMPORT_COMPONENT(handles, EcsMatProject2D);

#undef DeclareHandle

#ifdef __cplusplus
}
#endif

#endif
