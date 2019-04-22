#include <include/transform.h>
#include <string.h>

void FlecsComponentsTransformImport(
    ecs_world_t *world,
    int flags)
{
    bool do_2d = !flags || flags & ECS_2D;
    bool do_3d = !flags || flags & ECS_3D;

    ECS_MODULE(world, FlecsComponentsTransform);

    if (do_2d) {
        ECS_COMPONENT(world, EcsPosition2D);
        ECS_COMPONENT(world, EcsScale2D);
        ECS_COMPONENT(world, EcsRotation2D);
        ECS_COMPONENT(world, EcsMatTransform2D);
        ECS_COMPONENT(world, EcsMatProject2D);

        ECS_SET_COMPONENT(handles, EcsPosition2D);
        ECS_SET_COMPONENT(handles, EcsScale2D);
        ECS_SET_COMPONENT(handles, EcsRotation2D);
        ECS_SET_COMPONENT(handles, EcsMatTransform2D);
        ECS_SET_COMPONENT(handles, EcsMatProject2D);
    }

    if (do_3d) {
        ECS_COMPONENT(world, EcsPosition3D);
        ECS_COMPONENT(world, EcsScale3D);
        ECS_COMPONENT(world, EcsRotation3D);

        ECS_SET_COMPONENT(handles, EcsPosition3D);
        ECS_SET_COMPONENT(handles, EcsScale3D);
        ECS_SET_COMPONENT(handles, EcsRotation3D);
    }
}
