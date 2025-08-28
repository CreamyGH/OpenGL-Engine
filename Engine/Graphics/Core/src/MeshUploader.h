#pragma once

#include "Log.h"
#include "MeshGPU.h"
#include "VertexLayout.h"

#include <stdint.h>
#include <map>
#include <memory>

using MeshHandle = uint32_t;

class MeshUploader
{
public:
    virtual ~MeshUploader() = default;

    MeshHandle CreateMeshHandle(const std::vector<uint8_t>& rawVertices, const std::vector<uint32_t>& indices, const VertexLayout& vertexLayout);
    void ReleaseHandle(MeshHandle handle);
    const std::shared_ptr<MeshGPU> GetMeshGPU(MeshHandle handle);

protected:
    virtual const std::shared_ptr<MeshGPU> UploadMesh(const std::vector<uint8_t>& rawVertices, const std::vector<uint32_t>& indices, const VertexLayout& vertexLayout) = 0;

private:
    MeshHandle m_NextHandle = 0;
    std::map<MeshHandle, std::shared_ptr<MeshGPU>> m_HandleToMesh;
};