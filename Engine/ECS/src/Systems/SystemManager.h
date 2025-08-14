#pragma once

#include "System.h"

#include "Helpers/Singleton.h"
#include "Timestep.h"

//TODO create and publish component events

namespace ECS
{
	class SystemManager : public Singleton<SystemManager>
	{
		friend class Singleton<SystemManager>;
	public:
		template<typename SystemT>
		void RegisterSystem()
		{
			auto system = std::make_unique<SystemT>();
			uint32_t execOrder = system->GetExecOrder();

			LOG_ASSERT(!m_SystemsByOrder.contains(execOrder), "System with this order already exists");

			m_SystemsByOrder[execOrder] = std::move(system);
		}

		void UpdateSystems(entt::registry& activeRegistry, Core::Timestep timestep)
		{
			for (size_t order = 0; order < m_SystemsByOrder.size(); order++)
			{
				m_SystemsByOrder[order]->OnUpdate(activeRegistry, timestep);
			}
		}

	private:
		std::map<uint32_t, std::unique_ptr<System>> m_SystemsByOrder;
	};
}