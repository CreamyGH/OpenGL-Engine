#include "CameraSystem.h"

namespace ECS
{
    void CameraSystem::OnSystemCreate()
    {
        AttachOnUpdateComponent<CameraComponent>();
    }
    
    
    void CameraSystem::ModifyFrameData(FrameData &frameData)
    {
        //TODO pass data to framedata
    }

    void CameraSystem::OnComponentUpdate(entt::entity entity, CameraComponent &camera)
    {
        
    }
}