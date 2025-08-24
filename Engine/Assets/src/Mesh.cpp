#include "Mesh.h"

void Mesh::SetVertices(const std::vector<Vertex> vertices)
{
    m_Vertices = std::move(vertices);
    SyncRawVertices();
}


void Mesh::SyncRawVertices()
{
    m_RawVertices.resize(m_Vertices.size() * sizeof(Vertex));
    std::memcpy(m_RawVertices.data(), m_Vertices.data(), m_RawVertices.size());
}

void Mesh::SetVertexLayout()
{
    m_VertexLayout.stride = sizeof(Vertex);
    
    m_VertexLayout.attribs = {
        {POSITION_LOCATION, ShaderDataType::Float3, offsetof(Vertex, position)},
        {NORMAL_LOCATION, ShaderDataType::Float3, offsetof(Vertex, normal)},
        {UV_LOCATION, ShaderDataType::Float2, offsetof(Vertex, uv)}
    };


}

void Mesh::AttachMeshGPU(const MeshGPU &meshGPU)
{
    m_MeshGPU = meshGPU;
    m_IsMeshGPUAttached = true;
}

const MeshGPU &Mesh::getMeshGPU() const
{
    LOG_ASSERT(m_IsMeshGPUAttached, "This mesh doesnt have MeshGPU attached");
    return m_MeshGPU;
}
