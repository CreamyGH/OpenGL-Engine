#pragma once

#include <memory>
#include "MeshUploadData.h"
#include "VertexData.h"

class MeshPacker
{
public:
    std::unique_ptr<MeshUploadData> PackMesh(const std::vector<Vertex>& vertices, 
        const std::vector<uint32_t>& indices,
        const VertexLayout& layout
    );
    
private:
    std::vector<uint8_t>& ParseVertices(const std::vector<Vertex>& vertices);
};