#include "pch.h"
#include "Window.h" 

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Core
{
	Window::Window(const std::string& name, uint32_t width, uint32_t height) : m_Width(width), m_Height(height)
	{
		if (!glfwInit()) {
			LOG_ERROR("GLFW failed to initalize!");
			return;
		}

		m_Handle = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Handle);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		//LOG_ASSERT(status, "Failed to initialize Glad!");

		//LOG_INFO("OpenGL Info:");
		//LOG_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		//LOG_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		//LOG_INFO("  Version: {0}", glGetString(GL_VERSION));

		glfwSetWindowUserPointer(m_Handle, this);
		
		glfwSetWindowSizeCallback(m_Handle, [](GLFWwindow* window, int width, int height)
		{
			Window* wnd = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
			wnd->resized = true;
			wnd->m_Width = width;
			wnd->m_Height = height;
		});

		SetInputCallbacks();
	}

	void Window::SetInputCallbacks()
	{
		//TODO add when event system is ready
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