#pragma once
#include "Application.h"

#include "Events/KeyEvent.h"

class SandboxApp : public Core::Application
{
public:
	SandboxApp() = default;

	void OnCreate() override;
	void OnUpdate(Core::Timestep timestep) override;
	void OnDestroy() override;

private:
	bool TestEventFunction(Core::TestEvent& e);
};