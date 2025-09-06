#pragma once

#include <unordered_map>
#include <memory>

#include "TextureUploader.h"
#include "GLTextureGPU.h"

class GLTextureUploader : public TextureUploader
{
public:
    virtual TextureHandle CreateTextureHandle(const std::vector<uint8_t>& pixelData, const TextureDesc& desc, const SamplerDesc& sampler, const TextureViewDesc& view) override;
    void ReleaseHandle(TextureHandle handle) override;

    const GLTextureGPU* GetTextureGPU(TextureHandle handle) override { return m_UploadedTextures[handle].get(); }
    void CleanAllTextures() override;

private:
    void GenerateGLObjects(GLTextureGPU* texture);
    void DeleteGLObjects(GLTextureGPU* texture);

    void SetTexture(const std::vector<uint8_t>& pixelData, const TextureDesc& textureDesc, GLTextureGPU* texture);
    void SetSampler(const SamplerDesc& sampler, GLTextureGPU* texture);
    void SetTextureView(const TextureViewDesc& view, GLTextureGPU* texture);

private:
    std::unordered_map<TextureHandle, std::unique_ptr<GLTextureGPU>> m_UploadedTextures;
    TextureHandle m_NextHandle = 1;
};