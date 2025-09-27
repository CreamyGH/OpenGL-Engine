#pragma once

#include <unordered_map>
#include <memory>

#include <glad/glad.h>

#include "Log.h"

#include "GeometryAllocator.h"
#include "GLMeshGPU.h"
#include "GLShaderDataType.h"

class GLGeometryAllocator : public GeometryAllocator
{
public:
    virtual std::unique_ptr<MeshGPU> UploadMeshStatic(const MeshUploadData* meshData) override;

    virtual std::unique_ptr<MeshGPU> UploadMeshesStatic(
        const std::vector<std::unique_ptr<MeshUploadData>>& meshDataArr) override; //TODO


    virtual std::unique_ptr<MeshGPU> UploadMeshDynamic(const MeshUploadData* meshData) override; //TODO

    virtual std::unique_ptr<MeshGPU> UploadMeshesDynamic(
        const std::vector<std::unique_ptr<MeshUploadData>>& meshDataArr) override; //TODO

private:
    void GenerateGLObjects(GLMeshGPU* meshGPU);

    void SetVAO(const VertexLayout& vertexLayout, GLMeshGPU* meshGPU);
    void SetVBO(const std::vector<uint8_t> rawVertices, GLMeshGPU* meshGPU);
    void SetEBO(const std::vector<uint32_t> indices, GLMeshGPU* meshGPU);
};