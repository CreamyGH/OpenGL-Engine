#include "CameraSystem.h"

namespace ECS
{
    void CameraSystem::OnSystemBeginScene()
    {
        AttachAll<CameraComponent>();
    }

    void CameraSystem::OnSystemEndScene()
    {
        DetachAll<CameraComponent>();
    }

    void CameraSystem::ModifyFrameData(FrameData &frameData)
    {
        //TODO pass data to framedata
    }

    void CameraSystem::OnComponentConstruct(entt::registry &registry, entt::entity entity)
    {
        LOG_INFO("Camera constructed");
    }

    void CameraSystem::OnComponentUpdate(entt::registry &registry, entt::entity entity)
    {
        //TODO calculate view and projection matrices
    }
}