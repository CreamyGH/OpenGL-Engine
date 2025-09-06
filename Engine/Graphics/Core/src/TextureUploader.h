#pragma once

#include <vector>

#include "TextureGPU.h"
#include "TextureDescriptors.h"

class TextureUploader
{
public:
    virtual  ~TextureUploader() = default;

    virtual TextureHandle CreateTextureHandle(const std::vector<uint8_t>& pixelData, const TextureDesc& desc, const SamplerDesc& sampler, const TextureViewDesc& view) = 0;
    virtual void ReleaseHandle(TextureHandle handle) = 0;

    virtual const TextureGPU* GetTextureGPU(TextureHandle handle) = 0;

    virtual void CleanAllTextures() = 0;
};