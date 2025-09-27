#include "Mesh.h"

void Mesh::SetVertexLayout()
{
    m_VertexLayout.stride = sizeof(Vertex);
    
    m_VertexLayout.attribs = 
    {
        {POSITION_LOCATION, ShaderDataType::Float3, offsetof(Vertex, position)},
        {NORMAL_LOCATION, ShaderDataType::Float3, offsetof(Vertex, normal)},
        {UV_LOCATION, ShaderDataType::Float2, offsetof(Vertex, uv)}
    };
}