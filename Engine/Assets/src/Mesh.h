#pragma once

#include <vector>
#include <cstdint>
#include <cstring>

#include <glm/glm.hpp>

#include "Log.h"
#include "VertexLayout.h"

#define POSITION_LOCATION 0
#define NORMAL_LOCATION 1
#define UV_LOCATION 2

struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 uv;
};

class Mesh
{
public:
    void SetVertices(const std::vector<Vertex> vertices);
    inline void SetIndices(const std::vector<uint32_t> indices) { m_Indices = std::move(indices); }

    inline const std::vector<Vertex>& GetVertices() const { return m_Vertices; }
    inline const std::vector<uint32_t>& GetIndices() const { return m_Indices; }

    inline const VertexLayout& GetVertexLayout() const { return m_VertexLayout; }
    inline const std::vector<uint8_t>& GetRawVertices() const { return m_RawVertices; }

private:
    void SyncRawVertices();
    void SetVertexLayout();
    
private:
    std::vector<Vertex> m_Vertices;
    std::vector<uint32_t> m_Indices;

    std::vector<uint8_t> m_RawVertices;
    VertexLayout m_VertexLayout;
};