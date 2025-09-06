#include "GLTextureUploader.h"

TextureHandle GLTextureUploader::CreateTextureHandle(const std::vector<uint8_t> &pixelData, const TextureDesc &desc, const SamplerDesc &sampler, const TextureViewDesc &view)
{
    m_UploadedTextures[m_NextHandle] = std::make_unique<GLTextureGPU>();
    
    GLTextureGPU* texture = m_UploadedTextures[m_NextHandle].get();

    GenerateGLObjects(texture);

    SetTexture(pixelData, desc, texture);
    SetSampler(sampler, texture);
    SetTextureView(view, texture);
    
    m_NextHandle++;
    return m_NextHandle - 1;
}

void GLTextureUploader::ReleaseHandle(TextureHandle handle)
{

}

void GLTextureUploader::GenerateGLObjects(GLTextureGPU *texture)
{
    glGenTextures(1, &texture->id);
    glGenSamplers(1, &texture->sampler);
    glGenTextures(1, &texture->view);
}

void GLTextureUploader::DeleteGLObjects(GLTextureGPU *texture)
{
    glDeleteTextures(1, &texture->id);
    glDeleteTextures(1, &texture->view);
    glDeleteSamplers(1, &texture->sampler);
}

void GLTextureUploader::SetTexture(const std::vector<uint8_t> &pixelData, const TextureDesc &textureDesc, GLTextureGPU *texture)
{

}

void GLTextureUploader::SetSampler(const SamplerDesc &sampler, GLTextureGPU *texture)
{

}

void GLTextureUploader::SetTextureView(const TextureViewDesc &view, GLTextureGPU *texture)
{
    
}

void GLTextureUploader::CleanAllTextures()
{

}