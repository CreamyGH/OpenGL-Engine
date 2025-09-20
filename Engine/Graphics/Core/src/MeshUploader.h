#pragma once

#include <cstdint>

#include "MeshGPU.h"
#include "VertexLayout.h"


class MeshUploader
{
public:
    virtual ~MeshUploader() = default;

    virtual MeshHandle CreateMeshHandle(const std::vector<uint8_t>& rawVertices, const std::vector<uint32_t>& indices, const VertexLayout& vertexLayout) = 0;
    virtual void UpdateMeshHandle(MeshHandle oldHandle, const std::vector<uint8_t>& rawVertices, const std::vector<uint32_t>& indices, const VertexLayout& vertexLayout) = 0;

    virtual void ReleaseHandle(MeshHandle handle) = 0;
    virtual const MeshGPU* GetMeshGPU(MeshHandle handle) = 0;

    virtual void CleanAllMeshes() = 0;
};