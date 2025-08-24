#include "SandboxApp.h"


int main()
{
	Core::WindowConfig winConfig;

	winConfig.title = "OpenGL-Engine - Sandbox";
	winConfig.width = 800;
	winConfig.height = 600;
	winConfig.vSyncEnabled = true;

	std::unique_ptr<SandboxApp> app = std::make_unique<SandboxApp>();

	app->Init(winConfig);
	app->Run();
}