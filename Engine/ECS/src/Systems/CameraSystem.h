#pragma once
#include "Log.h"
#include "System.h"

#include "Components/CameraComponent.h"


namespace ECS
{
	class CameraSystem : public System
	{
	public:
		void OnSystemCreate() override;
		void ModifyFrameData(FrameData& frameData) override;

		SYSTEM_EXEC_ORDER(0)
		
	protected:
		void OnComponentConstruct(entt::registry& registry, entt::entity entity) override;
		void OnComponentUpdate(entt::registry& registry, entt::entity entity) override;
	};
}