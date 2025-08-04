#pragma once
#include "System.h"

namespace ECS
{
	class MotionSystem : public System
	{
	public:
		void OnCreate() override;
		void OnUpdate(entt::registry& registry, Core::Timestep timestep) override;
	};
}