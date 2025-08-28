#pragma once

#include "System.h"

#include "Helpers/Singleton.h"
#include "Timestep.h"

namespace ECS
{
	class SystemManager : public Singleton<SystemManager>
	{
	friend class Singleton<SystemManager>;
	
	public:
		void SetActiveRegistry(entt::registry* activeRegistry) 
		{
			for (size_t order = 0; order < m_SystemsByOrder.size(); order++)
			{
				m_SystemsByOrder[order]->OnSystemEndScene();
				m_SystemsByOrder[order]->SetActiveRegistry(activeRegistry);
				m_SystemsByOrder[order]->OnSystemBeginScene();
			}
		}

		template<typename SystemT>
		void RegisterSystem(entt::registry* activeRegistry)
		{
			auto system = std::make_unique<SystemT>();
			uint32_t execOrder = system->GetExecOrder();

			LOG_ASSERT(!m_SystemsByOrder.contains(execOrder), "System with this order already exists");

			system->SetActiveRegistry(activeRegistry);
			system->OnSystemCreate();
			system->OnSystemBeginScene();

			m_SystemsByOrder.emplace(execOrder, std::move(system));
		}

		void CollectFrameData(FrameData& frameData)
		{
			for (size_t order = 0; order < m_SystemsByOrder.size(); order++)
			{
				m_SystemsByOrder[order]->ModifyFrameData(frameData);
			}
		}

	private:
		std::map<uint32_t, std::unique_ptr<System>> m_SystemsByOrder;
	private:
		~SystemManager()
		{
			for (size_t order = 0; order < m_SystemsByOrder.size(); order++)
			{
				m_SystemsByOrder[order]->OnSystemDestroy();
			}
		}
	};
}