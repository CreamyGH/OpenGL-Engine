#pragma once

#include <glad/glad.h>
#include "ShaderDataType.h"


inline GLenum GLBaseType(ShaderDataType t)
{
    switch(t)
    {
        case ShaderDataType::Float:
        case ShaderDataType::Float2:
        case ShaderDataType::Float3:
        case ShaderDataType::Float4: return GL_FLOAT;
        case ShaderDataType::Int:
        case ShaderDataType::Int2:
        case ShaderDataType::Int3:
        case ShaderDataType::Int4:   return GL_INT;
        case ShaderDataType::UByte4N:return GL_UNSIGNED_BYTE;
    }
    return GL_FLOAT;
}
