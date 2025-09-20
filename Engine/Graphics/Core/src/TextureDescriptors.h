#pragma once

#include <stdint.h>

enum class TextureSemantic 
{
    Unknown = 0, BaseColor, Diffuse, Specular, Normal, Metalness, Roughness, AO,
    Emissive, Opacity, Height, Glossiness
};

enum class TextureFormat 
{ 
    RGBA8_UNorm, 
    RGBA8_sRGB, 
    RG16F, 
    RGBA16F, 
    RGBA32F,
    D24S8
};

enum class TextureDimension 
{
    Tex2D,
    Tex2DArray,
    Cube, 
    CubeArray, 
    Tex3D 
};

struct TextureDesc 
{
    TextureDimension dimension = TextureDimension::Tex2D;
    uint32_t width = 1, height = 1, depth = 1;
    uint32_t mipLevels = 1;
    TextureFormat format = TextureFormat::RGBA8_UNorm;
    bool generateMips = true;
};

enum class Filter 
{
    Nearest, 
    Linear, 
    Aniso 
};

enum class Address 
{ 
    Repeat,
    Clamp,
    Mirror
};

struct SamplerDesc 
{
    Filter  minFilter = Filter::Linear;
    Filter  magFilter = Filter::Linear;
    Address u = Address::Repeat, v = Address::Repeat, w = Address::Repeat;
    float   maxAniso = 1.0f;
};

struct TextureViewDesc 
{
    TextureDimension viewDim = TextureDimension::Tex2D;
    uint32_t baseMip = 0, mipCount = 1;
    uint32_t baseLayer = 0, layerCount = 1;

    TextureFormat viewFormat;
    bool hasFormatOverride = false;
};