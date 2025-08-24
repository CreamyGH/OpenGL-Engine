#pragma once
#include "System.h"

#include "Components/CameraComponent.h"

namespace ECS
{
	class CameraSystem : public System
	{
	public:
		void OnSystemCreate() override;		
		void ModifyFrameData(FrameData& frameData) override;

	protected:
		using System::OnComponentUpdate;

		void OnComponentUpdate(entt::entity entity, CameraComponent& camera);
	};
}