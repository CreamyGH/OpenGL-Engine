#include "pch.h"
#include "Application.h"

namespace Core
{
	void Application::Init(const WindowConfig& winConfig)
	{
		Log::Init();

		m_Window = std::make_shared<Window>(winConfig);

		Input::get().Init(m_Window->getHandle());		
	}

	void Application::Run()
	{
		OnCreate();

		float lastFrameTime = 0.0f;

		while (m_Window->isOpened())
		{
			Input::get().Update();

			float time = (float)glfwGetTime();
			Timestep timestep = time - lastFrameTime;
			lastFrameTime = time;

			OnUpdate(timestep);

			m_Window->Update();
		}

		OnDestroy();
	}
}