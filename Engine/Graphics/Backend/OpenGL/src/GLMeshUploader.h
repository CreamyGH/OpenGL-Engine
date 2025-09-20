#pragma once

#include <unordered_map>
#include <memory>

#include <glad/glad.h>

#include "Log.h"

#include "MeshUploader.h"
#include "GLMeshGPU.h"
#include "GLShaderDataType.h"

class GLMeshUploader : public MeshUploader
{
public:
    MeshHandle CreateMeshHandle(const std::vector<uint8_t>& rawVertices, const std::vector<uint32_t>& indices, const VertexLayout& vertexLayout) override;
    void UpdateMeshHandle(MeshHandle oldHandle, const std::vector<uint8_t>& rawVertices, const std::vector<uint32_t>& indices, const VertexLayout& vertexLayout) override;

    void ReleaseHandle(MeshHandle handle) override;

    const GLMeshGPU* GetMeshGPU(MeshHandle handle) override { m_UploadedMeshes[handle].get(); }
    void CleanAllMeshes() override;

private:
    void GenerateGLObjects(GLMeshGPU* meshGPU);
    void DeleteGLObjects(GLMeshGPU* meshGPU);

    void SetVAO(const VertexLayout& vertexLayout, GLMeshGPU* meshGPU);
    void SetVBO(const std::vector<uint8_t> rawVertices, GLMeshGPU* meshGPU);
    void SetEBO(const std::vector<uint32_t> indices, GLMeshGPU* meshGPU);

private:
    std::unordered_map<MeshHandle, std::unique_ptr<GLMeshGPU>> m_UploadedMeshes;
    MeshHandle m_NextHandle = 1;
};