#pragma once
#include "System.h"

#include "Components/CameraComponent.h"

namespace ECS
{
	class CameraSystem : public System
	{
	public:
		void OnSystemCreate() override;		
		void OnUpdateCamera(entt::entity entity, CameraComponent& camera);
		void ModifyFrameData(FrameData& frameData) override;
	};
}