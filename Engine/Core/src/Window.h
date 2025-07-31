#pragma once

#include "pch.h"

#include <GLFW/glfw3.h>

namespace Core
{
	class Window
	{
	public:
		Window(const std::string& name, uint32_t width, uint32_t height);
		~Window();

		GLFWwindow* getHandle() { return m_Handle; }

		uint32_t getWidth() { return m_Width; }
		uint32_t getHeight() { return m_Height; }

		void SetVSync(bool enable);

		void Update();
		bool isOpened();

	public:
		bool resized = false;

	private:
		void SetInputCallbacks();

	private:
		GLFWwindow* m_Handle;
		uint32_t m_Width, m_Height;
	};
}