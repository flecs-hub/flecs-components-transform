#include <flecs_components_transform.h>
#include <string.h>

void FlecsComponentsTransformImport(
    ecs_world_t *world)
{
    ECS_MODULE(world, FlecsComponentsTransform);

    ecs_set_name_prefix(world, "Ecs");

    ECS_IMPORT(world, FlecsMeta);

    ECS_META(world, EcsPosition2);
    ECS_META(world, EcsPosition3);
    ECS_META(world, EcsScale2);
    ECS_META(world, EcsScale3);
    ECS_META(world, EcsRotation2);
    ECS_META(world, EcsRotation3);
    ECS_META(world, EcsQuaternion);

    ECS_COMPONENT(world, EcsTransform2);
    ECS_COMPONENT(world, EcsTransform3);
    ECS_COMPONENT(world, EcsProject2);
    ECS_COMPONENT(world, EcsProject3);

    ECS_EXPORT_COMPONENT(EcsPosition2);
    ECS_EXPORT_COMPONENT(EcsPosition3);
    ECS_EXPORT_COMPONENT(EcsScale2);
    ECS_EXPORT_COMPONENT(EcsScale3);
    ECS_EXPORT_COMPONENT(EcsRotation2);
    ECS_EXPORT_COMPONENT(EcsRotation3);
    ECS_EXPORT_COMPONENT(EcsQuaternion);
    ECS_EXPORT_COMPONENT(EcsTransform2);
    ECS_EXPORT_COMPONENT(EcsTransform3);
    ECS_EXPORT_COMPONENT(EcsProject2);
    ECS_EXPORT_COMPONENT(EcsProject3);
}
