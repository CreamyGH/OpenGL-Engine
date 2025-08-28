#include "MeshUploader.h"

MeshHandle MeshUploader::CreateMeshHandle(const std::vector<uint8_t> &rawVertices, const std::vector<uint32_t> &indices, const VertexLayout &vertexLayout)
{
    m_HandleToMesh[m_NextHandle] = UploadMesh(rawVertices, indices, vertexLayout);
    m_NextHandle++;

    return m_NextHandle - 1;
}

void MeshUploader::ReleaseHandle(MeshHandle handle)
{
    if (m_HandleToMesh.contains(handle))
    {
        m_HandleToMesh.erase(handle);
    }
}

const std::shared_ptr<MeshGPU> MeshUploader::GetMeshGPU(MeshHandle handle)
{
    LOG_ASSERT(m_HandleToMesh.contains(handle), "This MeshHandle doesnt exist!");

    return m_HandleToMesh[handle];
}
