#pragma once

#include <vector>
#include <cstdint>
#include <cstring>

#include <glm/glm.hpp>

#include "Log.h"

#include "ShaderDataType.h"
#include "MeshGPU.h"

#define POSITION_LOCATION 0
#define NORMAL_LOCATION 1
#define UV_LOCATION 2

struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 uv;
};

struct VertexAttribute 
{
    uint32_t location;
    ShaderDataType type;
    uint32_t offset;
};

struct VertexLayout 
{
    uint32_t stride;      
    std::vector<VertexAttribute> attribs;  
};

class Mesh
{
public:
    void SetVertices(const std::vector<Vertex> vertices);
    inline void SetIndices(const std::vector<uint32_t> indices) { m_Indices = std::move(indices); }

    inline const std::vector<Vertex>& GetVertices() const { return m_Vertices; }
    inline const std::vector<uint32_t>& GetIndices() const { return m_Indices; }

    const VertexLayout& GetVertexLayout() const { return m_VertexLayout; }

    void AttachMeshGPU(const MeshGPU& meshGPU);
    const MeshGPU& getMeshGPU() const;

private:
    void SyncRawVertices();
    void SetVertexLayout();
    
private:
    std::vector<Vertex> m_Vertices;
    std::vector<uint32_t> m_Indices;

    std::vector<uint8_t> m_RawVertices;
    VertexLayout m_VertexLayout;

    MeshGPU m_MeshGPU;
    bool m_IsMeshGPUAttached = false;
};