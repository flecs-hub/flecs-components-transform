#ifndef FLECS_COMPONENTS_TRANSFORM_H
#define FLECS_COMPONENTS_TRANSFORM_H

#include <flecs-components-transform/bake_config.h>

// Reflection system boilerplate
#undef ECS_META_IMPL
#ifndef flecs_components_transform_EXPORTS
#define ECS_META_IMPL EXTERN // Ensure meta symbols are only defined once
#endif

#ifndef FLECS_LEGACY

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

#endif

typedef struct EcsTransform2 {
    mat3 value;
} EcsTransform2;

typedef struct EcsTransform3 {
    mat4 value;
} EcsTransform3;

typedef struct EcsProject2 {
    mat3 value;
} EcsProject2;

typedef struct EcsProject3 {
    mat4 value;
} EcsProject3;

#ifdef __cplusplus
extern "C" {
#endif

FLECS_COMPONENTS_TRANSFORM_API
void FlecsComponentsTransformImport(
    ecs_world_t *world);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#ifndef FLECS_NO_CPP

namespace flecs {
namespace components {

class transform : FlecsComponentsTransform {
public:
    using Position2 = EcsPosition2;

    struct Position3 : EcsPosition3 {
        Position3() { }
        
        Position3(float x, float y, float z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        operator float*() {
            return reinterpret_cast<float*>(this);
        }
    };

    using Scale2 = EcsScale2;
    using Scale3 = EcsScale3;

    using Rotation2 = EcsRotation2;
    using Rotation3 = EcsRotation3;

    using Quaternion = EcsQuaternion;

    using Transform2 = EcsTransform2;
    using Transform3 = EcsTransform3;

    using Project2 = EcsProject2;
    using Project3 = EcsProject3;

    transform(flecs::world& ecs) {
        FlecsComponentsTransformImport(ecs);

        ecs.module<flecs::components::transform>();

        ecs.component<Position2>("::flecs::components::transform::Position2");
        ecs.component<EcsPosition3>();
            .component<Position3>();

        ecs.component<Scale2>("::flecs::components::transform::Scale2");
        ecs.component<Scale3>("::flecs::components::transform::Scale3");

        ecs.component<Rotation2>("::flecs::components::transform::Rotation2");
        ecs.component<Rotation3>("::flecs::components::transform::Rotation3");

        ecs.component<Quaternion>("::flecs::components::transform::Quaternion");

        ecs.component<Transform2>("::flecs::components::transform::Transform2");
        ecs.component<Transform3>("::flecs::components::transform::Transform3");

        ecs.component<Project2>("::flecs::components::transform::Project2");
        ecs.component<Project3>("::flecs::components::transform::Project3");
    }
};

}
}

#endif // FLECS_NO_CPP
#endif // __cplusplus

#endif // FLECS_COMPONENTS_TRANSFORM_H
