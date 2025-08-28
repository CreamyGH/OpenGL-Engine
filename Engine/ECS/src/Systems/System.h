#pragma once

#include <entt/entt.hpp>

#include "FrameData.h"
#include "Timestep.h"

namespace ECS
{
	#define SYSTEM_EXEC_ORDER(order) virtual uint32_t GetExecOrder() const override { return order; }

	class System
	{
	public:
        virtual ~System() = default;

		inline void SetActiveRegistry(entt::registry* activeRegistry) { m_Registry = activeRegistry; }

		virtual void OnSystemCreate() {}
		virtual void OnSystemDestroy() {}

        virtual void OnSystemBeginScene() {}
        virtual void OnSystemEndScene() {}

		virtual void ModifyFrameData(FrameData& frameData) {}

		virtual uint32_t GetExecOrder() const = 0;

	protected:
        virtual void OnComponentConstruct(entt::registry& registry, entt::entity entity) {}
        virtual void OnComponentUpdate(entt::registry& registry, entt::entity entity) {}
        virtual void OnComponentDestroy(entt::registry& registry, entt::entity entity) {}

        
        template<typename... Components>
        void AttachAll() {
            (AttachAllFor<Components>(), ...);
        }

        template<typename... Components>
        void DetachAll() {
            (DetachAllFor<Components>(), ...);
        }
        
    protected:
        entt::registry* m_Registry = nullptr;
        
    private:
        template<typename ComponentT>
        void AttachAllFor() 
        {
            LOG_ASSERT(m_Registry, "Registry not set");
            m_Registry->on_construct<ComponentT>()
                .template connect<&System::OnComponentConstruct>(*this);

            m_Registry->on_update<ComponentT>()
                .template connect<&System::OnComponentUpdate>(*this);

            m_Registry->on_destroy<ComponentT>()
                .template connect<&System::OnComponentDestroy>(*this);
        }

        template<typename ComponentT>
        void DetachAllFor() 
        {
            LOG_ASSERT(m_Registry, "Registry not set");
            m_Registry->on_construct<ComponentT>().disconnect(this);
            m_Registry->on_update<ComponentT>().disconnect(this);
            m_Registry->on_destroy<ComponentT>().disconnect(this);
        }
	};
}