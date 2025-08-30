#include "SandboxApp.h"

#include "BackendManager.h"
#include "GLBackend.h"

int main()
{
	BackendManager::get().SetBackend(std::make_unique<GLBackend>());
	
	Core::WindowConfig winConfig;
	
	winConfig.title = "OpenGL-Engine - Sandbox";
	winConfig.width = 800;
	winConfig.height = 600;
	winConfig.vSyncEnabled = true;
	
	std::unique_ptr<SandboxApp> app = std::make_unique<SandboxApp>();
	
	app->Init(winConfig);
	BackendManager::get().InitBackend();
	
	app->Run();
}