#pragma once

#include <vector>
#include <cstdint>
#include <VertexLayout.h>

struct MeshUploadData
{
    std::vector<uint8_t> rawVertices;
    std::vector<uint32_t> indices;

    VertexLayout layout;
    
    uint32_t vertexCount = 0;
    uint32_t indexCount  = 0;
    //AABB, lod, tangents ...
};