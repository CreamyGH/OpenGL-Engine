#pragma once

#include "Log.h"

#include <glad/glad.h>
#include "MeshGPU.h"

struct GLMeshGPU : public MeshGPU
{
    void Bind()
    {
        LOG_ASSERT(vao != 0, "This mesh was not uploaded");
        glBindVertexArray(vao);
    }

    void UnBind()
    {
        glBindVertexArray(0);
    }

    GLuint vbo = 0;
    GLuint ebo = 0;
    GLuint vao = 0;
};