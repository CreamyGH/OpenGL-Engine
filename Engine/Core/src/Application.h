#pragma once

#include "Window.h"
#include "Timestep.h"
#include "Log.h"

#include "Events/EventManager.h"

namespace Core
{	
	class Application
	{
	public:
		void Init(const WindowConfig& winConfig);

		void Run();

		virtual void OnCreate() = 0;
		virtual void OnUpdate(Timestep timestep) = 0;
		virtual void OnDestroy() = 0;

		const std::shared_ptr<Window>& getWindow() { return m_Window; }

	private:
		std::shared_ptr<Window> m_Window;
	};
}
