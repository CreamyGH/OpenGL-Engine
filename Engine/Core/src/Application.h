#pragma once

#include "Window.h"
#include "Timestep.h"
#include "Log.h"

namespace Core
{
	struct AppConfig
	{
		std::string title = "undefined";
		uint32_t windowWidth = 0;
		uint32_t windowHeight = 0;
		bool vsyncEnabled = false;
	};

	class Application
	{
	public:
		void Init(const AppConfig& config);

		void Run();

		virtual void OnCreate() = 0;
		virtual void OnUpdate(Timestep timestep) = 0;
		virtual void OnDestroy() = 0;

		const std::shared_ptr<Window>& getWindow() { return m_Window; }

	private:
		std::shared_ptr<Window> m_Window;
	};
}
