#pragma once

#include <vector>
#include <cstdint>

#include "TextureDescriptors.h"

class Texture
{
public:
    void SetPixelData(const std::vector<uint8_t>& pixels) { m_Pixels = pixels; }
    void ReleasePixelData() { m_Pixels.clear(); }
    bool HasPixelData() const { !m_Pixels.empty(); }

    void SetType(const TextureSemantic& semantic) { m_Semantic = semantic; }

    void SetDescription(const TextureDesc& dataDesc) { m_DataDesc = dataDesc; }
    void SetSamplerDesc(const SamplerDesc& samplerDesc) { m_SamplerDesc = samplerDesc; }
    void SetDescription(const TextureViewDesc& viewDesc) { m_ViewDesc = viewDesc; }

    const TextureDesc& GetDescription() const { return m_DataDesc; }
    const SamplerDesc& GetSamplerDesc() const { return m_SamplerDesc; }
    const TextureViewDesc& GetViewDesc() const { return m_ViewDesc; }

private:
    std::vector<uint8_t> m_Pixels;

    TextureSemantic m_Semantic;

    TextureDesc m_DataDesc;
    SamplerDesc m_SamplerDesc;
    TextureViewDesc m_ViewDesc;
};