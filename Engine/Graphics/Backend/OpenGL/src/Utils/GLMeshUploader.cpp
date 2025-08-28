#include "GLMeshUploader.h"

const std::shared_ptr<MeshGPU> GLMeshUploader::UploadMesh(const std::vector<uint8_t> &rawVertices, const std::vector<uint32_t> &indices, const VertexLayout &vertexLayout)
{
    //TODO
    return std::shared_ptr<MeshGPU>();
}

void GLMeshUploader::GenerateGLObjects(GLMeshGPU &meshGPU)
{
    glGenVertexArrays(1, &meshGPU.vao);
    glGenBuffers(1, &meshGPU.vbo);
    glGenBuffers(1, &meshGPU.ebo);
}

void GLMeshUploader::SetVAO(const VertexLayout &vertexLayout, GLMeshGPU &meshGPU)
{
    glBindVertexArray(meshGPU.vao);

    glBindBuffer(GL_ARRAY_BUFFER, meshGPU.vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, meshGPU.ebo);

    for (const VertexAttribute& vertexAttrib : vertexLayout.attribs)
    {   
        GLint size = ComponentCount(vertexAttrib.type);
        GLenum type = GLBaseType(vertexAttrib.type);
        GLboolean normalized = IsNormalized(vertexAttrib.type);


        glVertexAttribPointer(vertexAttrib.location, size, type, normalized, vertexLayout.stride, reinterpret_cast<const void*>(vertexAttrib.offset));
        glEnableVertexAttribArray(vertexAttrib.location);
    }

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void GLMeshUploader::SetVBO(const std::vector<uint8_t> rawVertices, GLMeshGPU &meshGPU)
{
    glBindBuffer(GL_ARRAY_BUFFER, meshGPU.vbo);
    glBufferData(GL_ARRAY_BUFFER, rawVertices.size(), rawVertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void GLMeshUploader::SetEBO(const std::vector<uint32_t> indices, GLMeshGPU &meshGPU)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, meshGPU.ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (size_t)(indices.size() * sizeof(uint32_t)), indices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
