#pragma once

#include <memory>

#include "TextureUploadData.h"
#include "TextureDescriptors.h"


class TextureUploader
{
public:
    virtual  ~TextureUploader() = default;

    virtual std::unique_ptr<TextureUploadData> UploadTexture(const std::vector<uint8_t>& pixelData, 
        const TextureDesc& desc, 
        const SamplerDesc& sampler, 
        const TextureViewDesc& view) {}

    virtual std::unique_ptr<TextureUploadData> UploadTexture(const std::vector<uint8_t>& pixelData, 
        const TextureDesc& desc, 
        const SamplerDesc& sampler) {}
};