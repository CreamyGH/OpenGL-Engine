#pragma once

#include <entt/entt.hpp>

#include "FrameData.h"
#include "Timestep.h"

namespace ECS
{
	#define SYSTEM_EXEC_ORDER(order) virtual uint32_t GetExecOrded() const override { return order; }
    #define BIND_COMP_FN(ComponentT, method) \
    [this](entt::entity e, ComponentT& comp) { this->method(e, comp); }

    template<typename ComponentT>
    using ComponentCallback = std::function<void(entt::entity, ComponentT&)>;

	class System
	{
	public:
		inline void SetActiveRegistry(entt::registry* activeRegistry) { m_Registry = activeRegistry; }
		virtual void OnSystemCreate() {}
		virtual void OnSystemDestroy() {}

		virtual void ModifyFrameData(FrameData& frameData) {}

		virtual uint32_t GetExecOrded() const = 0;

	protected:
        template<typename ComponentT>
        void OnComponentConstruct(entt::entity, ComponentT&) {}

        template<typename ComponentT>
        void OnComponentUpdate(entt::entity, ComponentT&) {}

        template<typename ComponentT>
        void OnComponentDestroy(entt::entity, ComponentT&) {}

        template<typename ComponentT>
        void AttachOnConstructComponent() 
        {
            m_Registry->on_construct<ComponentT>()
                .connect<&System::OnConstructAdapter<ComponentT>>(this);
        }

        template<typename ComponentT>
        void AttachOnUpdateComponent() 
        {
            m_Registry->on_update<ComponentT>()
                .connect<&System::OnUpdateAdapter<ComponentT>>(this);
        }

        template<typename ComponentT>
        void AttachOnDestroyComponent() 
        {
            m_Registry->on_destroy<ComponentT>()
                .connect<&System::OnDestroyAdapter<ComponentT>>(this);
        }

        template<typename ComponentT>
        void OnConstructAdapter(entt::registry& reg, entt::entity e) 
        {
            auto& comp = reg.get<ComponentT>(e);
            OnComponentConstruct(e, comp);
        }

        template<typename ComponentT>
        void OnUpdateAdapter(entt::registry& reg, entt::entity e) 
        {
            auto& comp = reg.get<ComponentT>(e);
            OnComponentUpdate(e, comp);
        }

        template<typename ComponentT>
        void OnDestroyAdapter(entt::registry& reg, entt::entity e) 
        {
            auto& comp = reg.get<ComponentT>(e);
            OnComponentDestroy(e, comp);
        }

    protected:
        entt::registry* m_Registry = nullptr;
	};
}