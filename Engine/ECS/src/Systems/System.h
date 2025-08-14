#pragma once

#include "Timestep.h"
#include "entt/entt.hpp"

//TODO add funcitions when component:
// has been added
// has been modified
// has been deleted
// and add pointer to that specific component

namespace ECS
{
	#define SYSTEM_EXEC_ORDER(order) virtual uint32_t GetExecOrded() const override { return order; }

	class System
	{
	public:
		virtual void OnSystemCreate() {};
		virtual void OnSystemDestroy() {};

		//virtual void OnUpdate(entt::registry& registry, Core::Timestep timestep) = 0;

		virtual uint32_t GetExecOrded() const = 0;
	};
}
