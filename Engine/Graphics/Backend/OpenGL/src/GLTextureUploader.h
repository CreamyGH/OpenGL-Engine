#pragma once

#include <unordered_map>
#include <memory>

#include "Log.h"

#include "TextureUploader.h"
#include "GLTextureGPU.h"

class GLTextureUploader : public TextureUploader
{
public:
    virtual TextureHandle CreateTextureHandle(const std::vector<uint8_t>& pixelData, const TextureDesc& desc, const SamplerDesc& sampler, const TextureViewDesc& view) override;
    virtual void UpdateTextureHandle(TextureHandle oldHandle, const std::vector<uint8_t>& pixelData, const TextureDesc& desc, const SamplerDesc& sampler, const TextureViewDesc& view) override;

    void ReleaseHandle(TextureHandle handle) override;
    const GLTextureGPU* GetTextureGPU(TextureHandle handle) override { return m_UploadedTextures[handle].get(); }
    void CleanAllTextures() override;

private:
    void GenerateGLObjects(GLTextureGPU* texture, TextureDimension dimension);
    void DeleteGLObjects(GLTextureGPU* texture);

    void SetTexture(const std::vector<uint8_t>& pixelData, const TextureDesc& textureDesc, GLTextureGPU* texture);
    void SetSampler(const SamplerDesc& sampler, GLTextureGPU* texture);

    void UpdateBindlessHandle(GLTextureGPU* texture);
    void ClearBindlessHandle(GLTextureGPU* texture);

    //Helpers
    GLenum ToGLInternalFormat(TextureFormat format);
    void ToGLUploadFormatType(TextureFormat f, GLenum& fmt, GLenum& type);

    GLenum ToGLTarget(TextureDimension dimension);

    GLenum PickGLMinFilter(Filter filter, bool hasMips);
    GLenum PickGLMagFilter(Filter filter);

    GLenum ToGLWrap(Address adress);

    bool GLHasMips(GLuint tex);

private:
    std::unordered_map<TextureHandle, std::unique_ptr<GLTextureGPU>> m_UploadedTextures;
    TextureHandle m_NextHandle = 1;
};