#include <include/transform.h>
#include <string.h>

void EcsComponentsTransform(
    EcsWorld *world,
    int flags,
    void *handles_out)
{
    bool do_2d = !flags || flags & ECS_2D;
    bool do_3d = !flags || flags & ECS_3D;
    EcsComponentTransformHandles *handles = handles_out;
    memset(handles, 0, sizeof(EcsComponentTransformHandles));

    if (do_2d) {
        ECS_COMPONENT(world, EcsPosition2D);
        ECS_COMPONENT(world, EcsScale2D);
        ECS_COMPONENT(world, EcsRotation2D);

        handles->Position2D = EcsPosition2D_h;
        handles->Scale2D = EcsScale2D_h;
        handles->Rotation2D = EcsRotation2D_h;

    }

    if (do_3d) {
        ECS_COMPONENT(world, EcsPosition3D);
        ECS_COMPONENT(world, EcsScale3D);
        ECS_COMPONENT(world, EcsRotation3D);
        ECS_COMPONENT(world, EcsQuaternion);

        handles->Position3D = EcsPosition3D_h;
        handles->Scale3D = EcsScale3D_h;
        handles->Rotation3D = EcsRotation3D_h;
        handles->Quaternion = EcsQuaternion_h;
    }
}
