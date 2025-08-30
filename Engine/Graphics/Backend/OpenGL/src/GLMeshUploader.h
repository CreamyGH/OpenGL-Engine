#pragma once

#include <glad/glad.h>

#include "MeshUploader.h"
#include "GLMeshGPU.h"
#include "GLShaderDataType.h"

class GLMeshUploader : public MeshUploader
{
protected:
    const std::shared_ptr<MeshGPU> UploadMesh(const std::vector<uint8_t>& rawVertices, const std::vector<uint32_t>& indices, const VertexLayout& vertexLayout) override;

private:
    void GenerateGLObjects(GLMeshGPU& meshGPU);

    void SetVAO(const VertexLayout& vertexLayout, GLMeshGPU& meshGPU);
    void SetVBO(const std::vector<uint8_t> rawVertices, GLMeshGPU& meshGPU);
    void SetEBO(const std::vector<uint32_t> indices, GLMeshGPU& meshGPU);
};