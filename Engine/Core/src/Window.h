#pragma once
#include "pch.h"

#include "Events/EventManager.h"

#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/WindowEvent.h"

#include <GLFW/glfw3.h>

namespace Core
{
	struct WindowConfig
	{
		std::string title;
		uint32_t width;
		uint32_t height;
		bool vSyncEnabled;
	};

	class Window
	{
	public:
		Window(const WindowConfig& config);
		~Window();

		GLFWwindow* getHandle() { return m_Handle; }

		uint32_t getWidth() const { return m_Width; }
		uint32_t getHeight() const { return m_Height; }

		void SetVSync(bool enable);

		void Update();
		bool isOpened();

	private:
		void SetInputCallbacks();
		void SetWindowCallbacks();

	private:
		GLFWwindow* m_Handle = nullptr;
		uint32_t m_Width = 0;
		uint32_t m_Height = 0;
	};
}