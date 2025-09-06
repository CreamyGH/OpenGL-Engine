#pragma once

#include <glad/glad.h>
#include "TextureGPU.h"

struct GLTextureGPU : public TextureGPU
{
    GLuint id = 0;
    GLuint sampler = 0;
    GLuint view = 0;
    GLuint64 bindlessHandle = 0;
};