#include "SandboxApp.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

using namespace Core;

void SandboxApp::OnCreate()
{
	LOG_INFO("Created sandboxApp");

	EVENT_LOG_CATEGORY(EventCategories::Window);

	//m_EventManager.AddListenerFunc<KeyTypedEvent>(BIND_EVENT_FN(KeyPressed));
}

void SandboxApp::OnUpdate(Timestep timestep)
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//LOG_INFO("XY: {0},{1}", m_Input.GetMouseX(), m_Input.GetMouseY());

	// if (m_Input.IsKeyPressed(KEY_W)) {
	// 	LOG_INFO("Pressing W");
	// }
}


void SandboxApp::OnDestroy()
{
	LOG_INFO("Destroyed sandboxApp");
}