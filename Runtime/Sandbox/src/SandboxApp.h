#pragma once
#include "Application.h"

#include "Events/EventManager.h"

class SandboxApp : public Core::Application
{
public:
	SandboxApp() = default;

	void OnCreate() override;
	void OnUpdate(Core::Timestep timestep) override;
	void OnDestroy() override;


private:
	Core::Input& m_Input = Core::Input::get();
	Core::EventManager& m_EventManager = Core::EventManager::get();
};