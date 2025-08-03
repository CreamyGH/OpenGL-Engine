#include "SandboxApp.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

using namespace Core;

void SandboxApp::OnCreate()
{
	LOG_INFO("Created sandboxApp");

	EVENT_LOG_CATEGORY(EventCategory::EventCategoryKeyboard);

	EventManager::get().AddListenerFunc<TestEvent>(BIND_EVENT_FN(TestEventFunction));

	TestEvent testEvent;
	PUBLISH_EVENT(testEvent);
}

void SandboxApp::OnUpdate(Timestep timestep)
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

bool SandboxApp::TestEventFunction(TestEvent& e)
{
	LOG_INFO("Test Event occured");
	return true;
}

void SandboxApp::OnDestroy()
{
	LOG_INFO("Destroyed sandboxApp");
}
