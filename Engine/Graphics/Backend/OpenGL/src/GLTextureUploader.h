#pragma once

#include <unordered_map>
#include <memory>

#include "Log.h"

#include "TextureUploader.h"
#include "GLTextureUploadData.h"

class GLTextureUploader : public TextureUploader
{
public:
    std::unique_ptr<TextureUploadData> UploadTexture(const std::vector<uint8_t>& pixelData, 
        const TextureDesc& desc,
        const SamplerDesc& sampler) override;

private:
    void GenerateGLObjects(GLTextureUploadData* texture, TextureDimension dimension);

    void SetTexture(const std::vector<uint8_t>& pixelData, const TextureDesc& textureDesc, GLTextureUploadData* texture);
    void SetSampler(const SamplerDesc& sampler, GLTextureUploadData* texture);

    void UpdateBindlessHandle(GLTextureUploadData* texture);

    //Helpers
    GLenum ToGLInternalFormat(TextureFormat format);
    void ToGLUploadFormatType(TextureFormat f, GLenum& fmt, GLenum& type);

    GLenum ToGLTarget(TextureDimension dimension);

    GLenum PickGLMinFilter(Filter filter, bool hasMips);
    GLenum PickGLMagFilter(Filter filter);

    GLenum ToGLWrap(Address adress);

    bool GLHasMips(GLuint tex);
};