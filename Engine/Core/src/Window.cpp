#include "pch.h"
#include "Window.h" 

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Core
{
	Window::Window(const WindowConfig& config) : m_Width(config.width), m_Height(config.height)
	{
		if (!glfwInit()) {
			LOG_ERROR("GLFW failed to initalize!");
			return;
		}

		m_Handle = glfwCreateWindow(config.width, config.height, config.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Handle);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		LOG_ASSERT(status, "Failed to initialize Glad!");

		LOG_INFO("OpenGL Info:");

		std::string vendorStr((const char*)glGetString(GL_VENDOR));
		std::string rendererStr((const char*)glGetString(GL_RENDERER));
		std::string versionStr((const char*)glGetString(GL_VERSION));

		LOG_INFO("  Vendor: {0}", vendorStr);
		LOG_INFO("  Renderer: {0}", rendererStr);
		LOG_INFO("  Version: {0}", versionStr);

		glfwSetWindowUserPointer(m_Handle, this);
		
		glfwSetWindowSizeCallback(m_Handle, [](GLFWwindow* window, int width, int height)
		{
			Window* wnd = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
			wnd->m_Width = width;
			wnd->m_Height = height;
		});

		SetVSync(config.vSyncEnabled);

		SetWindowCallbacks();
		SetInputCallbacks();
		//Uwazaj bo nie ma viewportu nie wiem czy nie trzeba pozniej dodac
	}

	void Window::SetInputCallbacks()
	{
		//TODO add when event system is ready
	}

	void Window::SetWindowCallbacks()
	{
		glfwSetWindowSizeCallback(m_Handle, [](GLFWwindow* window, int width, int height)
		{
				Window* wnd = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
				wnd->m_Width = width;
				wnd->m_Height = height;
		});
	}

	void Window::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Handle);
	}

	bool Window::isOpened()
	{
		return !glfwWindowShouldClose(m_Handle);
	}

	void Window::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_Handle);
		glfwTerminate();
	}
}