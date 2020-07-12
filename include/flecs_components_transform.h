#ifndef FLECS_COMPONENTS_TRANSFORM_H
#define FLECS_COMPONENTS_TRANSFORM_H

#include <flecs-components-transform/bake_config.h>

#ifdef __cplusplus
extern "C" {
#endif

ECS_STRUCT(EcsPosition2, {
    float x;
    float y;
});

ECS_STRUCT(EcsPosition3, {
    float x;
    float y;
    float z;
});

ECS_STRUCT(EcsScale2, {
    float x;
    float y;
});

ECS_STRUCT(EcsScale3, {
    float x;
    float y;
    float z;
});

ECS_STRUCT(EcsRotation2, {
    float angle;
});

ECS_STRUCT(EcsRotation3, {
    float x;
    float y;
    float z;
});

ECS_STRUCT(EcsQuaternion, {
    float x;
    float y;
    float z;
    float w;
});

typedef mat3 EcsTransform2;
typedef mat4 EcsTransform3;

typedef mat3 EcsProject2;
typedef mat4 EcsProject3;

typedef struct FlecsComponentsTransform {
    ECS_DECLARE_COMPONENT(EcsPosition2);
    ECS_DECLARE_COMPONENT(EcsPosition3);
    ECS_DECLARE_COMPONENT(EcsScale2);
    ECS_DECLARE_COMPONENT(EcsScale3);
    ECS_DECLARE_COMPONENT(EcsRotation2);
    ECS_DECLARE_COMPONENT(EcsRotation3);
    ECS_DECLARE_COMPONENT(EcsQuaternion);
    ECS_DECLARE_COMPONENT(EcsTransform2);
    ECS_DECLARE_COMPONENT(EcsTransform3);
    ECS_DECLARE_COMPONENT(EcsProject2);
    ECS_DECLARE_COMPONENT(EcsProject3);
} FlecsComponentsTransform;

FLECS_COMPONENTS_TRANSFORM_EXPORT
void FlecsComponentsTransformImport(
    ecs_world_t *world);

#define FlecsComponentsTransformImportHandles(handles)\
    ECS_IMPORT_COMPONENT(handles, EcsPosition2);\
    ECS_IMPORT_COMPONENT(handles, EcsPosition3);\
    ECS_IMPORT_COMPONENT(handles, EcsScale2);\
    ECS_IMPORT_COMPONENT(handles, EcsScale3);\
    ECS_IMPORT_COMPONENT(handles, EcsRotation2);\
    ECS_IMPORT_COMPONENT(handles, EcsRotation3);\
    ECS_IMPORT_COMPONENT(handles, EcsQuaternion);\
    ECS_IMPORT_COMPONENT(handles, EcsTransform2);\
    ECS_IMPORT_COMPONENT(handles, EcsTransform3);\
    ECS_IMPORT_COMPONENT(handles, EcsProject2);\
    ECS_IMPORT_COMPONENT(handles, EcsProject3);

#undef DeclareHandle

#ifdef __cplusplus
}
#endif

#endif
