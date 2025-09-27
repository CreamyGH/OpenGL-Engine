#pragma once

#include <glad/glad.h>
#include "TextureUploadData.h"

struct GLTextureUploadData : public TextureUploadData
{
    ~GLTextureUploadData() override
    {
        if (bindlessHandle) glMakeTextureHandleNonResidentARB(bindlessHandle);
        if (id)      glDeleteTextures(1, &id);
        if (sampler) glDeleteSamplers(1, &sampler);
    }

    GLuint id = 0;
    GLuint sampler = 0;
    GLuint64 bindlessHandle = 0;
};