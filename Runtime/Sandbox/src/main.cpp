#include "SandboxApp.h"


int main()
{
	Core::WindowConfig winConfig;

	winConfig.title = "OpenGL-Engine - Sandbox";
	winConfig.width = 1920;
	winConfig.height = 1080;
	winConfig.vSyncEnabled = true;

	std::unique_ptr<SandboxApp> app = std::make_unique<SandboxApp>();

	app->Init(winConfig);
	app->Run();
}