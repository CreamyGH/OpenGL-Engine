#pragma once
#include "Application.h"

#include "Events/EventManager.h"

#include "Systems/SystemManager.h"
#include "Systems/CameraSystem.h"

class SandboxApp : public Core::Application
{
public:
	SandboxApp() = default;

	void OnCreate() override;
	void OnUpdate(Core::Timestep timestep) override;
	void OnDestroy() override;

private:
	Core::Input& m_Input = Core::Input::get();
	ECS::SystemManager& m_SystemManager = ECS::SystemManager::get();
};