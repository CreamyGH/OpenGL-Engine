#include "CameraSystem.h"

void ECS::CameraSystem::OnSystemCreate()
{
    AttachOnUpdateComponent<CameraComponent>(BIND_COMP_FN(CameraComponent, OnUpdateCamera));
}

void ECS::CameraSystem::OnUpdateCamera(entt::entity entity, CameraComponent &camera)
{
    //TODO calulate view proj matrix
}

void ECS::CameraSystem::ModifyFrameData(FrameData &frameData)
{
    //TODO pass data to framedata
}
