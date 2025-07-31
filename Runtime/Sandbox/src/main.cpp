#include "SandboxApp.h"


int main()
{
	Core::AppConfig config;

	config.title = "OpenGL-Engine - Sandbox";
	config.windowWidth = 1920;
	config.windowHeight = 1080;
	config.vsyncEnabled = true;

	std::unique_ptr<SandboxApp> app = std::make_unique<SandboxApp>();

	app->Init(config);
	app->Run();
}