#include "SandboxApp.h"

void SandboxApp::OnCreate()
{
	LOG_INFO("Created sandbox APP!");
}

void SandboxApp::OnUpdate(Core::Timestep timestep)
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void SandboxApp::OnDestroy()
{
	LOG_INFO("Destroyed sandbox APP");
}