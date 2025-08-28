#pragma once

#include "ShaderDataType.h"
#include <vector>

struct VertexAttribute 
{
    uint32_t location;
    ShaderDataType type;
    uintptr_t offset;
};

struct VertexLayout 
{
    uint32_t stride;      
    std::vector<VertexAttribute> attribs;  
};