#include "MeshUploader.h"

const MeshGPU MeshUploader::UploadSingleMesh(uint32_t meshID)
{
    //TODO

    //GenerateGLObjects()
    //SetVBO()
    //SetEBO()
    //SetVAO()
}

const MeshGPU MeshUploader::UploadMultipleMeshes(const std::vector<uint32_t> &meshIDs)
{
    //TODO
}

void MeshUploader::GenerateGLObjects(MeshGPU &meshGPU)
{
    glGenVertexArrays(1, &meshGPU.vao);
    glGenBuffers(1, &meshGPU.vbo);
    glGenBuffers(1, &meshGPU.ebo);
}

void MeshUploader::SetVAO(const VertexLayout &vertexLayout, MeshGPU &meshGPU)
{
    glBindVertexArray(meshGPU.vao);

    glBindBuffer(GL_ARRAY_BUFFER, meshGPU.vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, meshGPU.ebo);

    for (const VertexAttribute& vertexAttrib : vertexLayout.attribs)
    {   
        GLint size = ComponentCount(vertexAttrib.type);
        GLenum type = GLBaseType(vertexAttrib.type);
        GLboolean normalized = IsNormalized(vertexAttrib.type);

        glVertexAttribPointer(vertexAttrib.location, size, type, normalized, vertexLayout.stride, (void*)vertexAttrib.offset);
        glEnableVertexAttribArray(vertexAttrib.location);
    }

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void MeshUploader::SetVBO(const std::vector<uint8_t> rawVertices, MeshGPU &meshGPU)
{
    glBindBuffer(GL_ARRAY_BUFFER, meshGPU.vbo);
    glBufferData(GL_ARRAY_BUFFER, rawVertices.size(), rawVertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void MeshUploader::SetEBO(const std::vector<uint32_t> indices, MeshGPU &meshGPU)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, meshGPU.ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (size_t)(indices.size() * sizeof(uint32_t)), indices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}