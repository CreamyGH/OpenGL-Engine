#pragma once

#include <glad/glad.h>
#include "MeshGPU.h"

struct GLMeshGPU : public MeshGPU
{
    void Bind() override
    {
        //TODO
    }

    void UnBind() override
    {
        //TODO
    }

    GLuint vbo = 0;
    GLuint ebo = 0;
    GLuint vao = 0;
};