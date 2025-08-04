#include "pch.h"
#include "Window.h" 

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
	}

	void Window::SetInputCallbacks()
	{
		glfwSetKeyCallback(m_Handle, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					PUBLISH_EVENT(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					PUBLISH_EVENT(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					PUBLISH_EVENT(event);
					break;
				}
			}
		});

		glfwSetCharCallback(m_Handle, [](GLFWwindow* window, uint32_t keycode)
		{
				KeyTypedEvent event(keycode);
				PUBLISH_EVENT(event);
		});

		glfwSetMouseButtonCallback(m_Handle, [](GLFWwindow* window, int button, int action, int mods)
		{
			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					PUBLISH_EVENT(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					PUBLISH_EVENT(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Handle, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			PUBLISH_EVENT(event);
		});

		glfwSetCursorPosCallback(m_Handle, [](GLFWwindow* window, double xPos, double yPos)
		{
			MouseMovedEvent event((float)xPos, (float)yPos);
			PUBLISH_EVENT(event);
		});
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