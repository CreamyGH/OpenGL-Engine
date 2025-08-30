#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Backend.h"
#include "GLMeshUploader.h"


class GLBackend : public Backend
{
public:
    const std::unique_ptr<MeshUploader> GetMeshUploader() override
    {
        std::unique_ptr<MeshUploader> meshUploader = std::make_unique<GLMeshUploader>();
        return meshUploader;
    }

protected:
    void InitBackend() override
    {
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		LOG_ASSERT(status, "Failed to initialize Glad!");

		LOG_INFO("OpenGL Info:");

		std::string vendorStr((const char*)glGetString(GL_VENDOR));
		std::string rendererStr((const char*)glGetString(GL_RENDERER));
		std::string versionStr((const char*)glGetString(GL_VERSION));

		LOG_INFO("  Vendor: {0}", vendorStr);
		LOG_INFO("  Renderer: {0}", rendererStr);
		LOG_INFO("  Version: {0}", versionStr);
    }

    void InitRenderers() override
    {
        //TODO add renderers
        //AddRenderer("GLDirectRenderer", std::make_unique<GLDirecrtRenderer>())
    }
};