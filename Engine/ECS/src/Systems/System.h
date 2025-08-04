#pragma once

#include "Timestep.h"
#include "entt/entt.hpp"

namespace ECS
{
#define SYSTEM_EXEC_ORDER(order) virtual uint32_t GetExecOrded() const override { return order; }

	class System
	{
	public:
		virtual void OnCreate() = 0;
		virtual void OnUpdate(entt::registry& registry, Core::Timestep timestep) = 0;

		virtual uint32_t GetExecOrded() const = 0;
	};
}
