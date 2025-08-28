#pragma once

enum class ShaderDataType 
{
    Float, Float2, Float3, Float4,
    Int,   Int2,   Int3,   Int4,
    UByte4N,
};

inline size_t SizeOf(ShaderDataType t) 
{
    switch(t)
    {
        case ShaderDataType::Float:  return 4;
        case ShaderDataType::Float2: return 8;
        case ShaderDataType::Float3: return 12;
        case ShaderDataType::Float4: return 16;
        case ShaderDataType::Int:    return 4;
        case ShaderDataType::Int2:   return 8;
        case ShaderDataType::Int3:   return 12;
        case ShaderDataType::Int4:   return 16;
        case ShaderDataType::UByte4N:return 4;
    }
    return 0;
}

inline int ComponentCount(ShaderDataType t)
{
    switch(t)
    {
        case ShaderDataType::Float:  return 1;
        case ShaderDataType::Float2: return 2;
        case ShaderDataType::Float3: return 3;
        case ShaderDataType::Float4: return 4;
        case ShaderDataType::Int:    return 1;
        case ShaderDataType::Int2:   return 2;
        case ShaderDataType::Int3:   return 3;
        case ShaderDataType::Int4:   return 4;
        case ShaderDataType::UByte4N:return 4;
    }
    return 0;
}

inline bool IsNormalized(ShaderDataType t) {
    return t == ShaderDataType::UByte4N ? true : false;
}