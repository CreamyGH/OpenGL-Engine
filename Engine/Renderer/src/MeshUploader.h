#pragma once

#include "Mesh.h"
#include "MeshGPU.h"

//TOOD

class MeshUploader
{
public:
    const MeshGPU UploadSingleMesh(uint32_t meshID);
    const MeshGPU UploadMultipleMeshes(const std::vector<uint32_t>& meshIDs);

private:
    void GenerateGLObjects(MeshGPU& meshGPU);

    void SetVAO(const VertexLayout& vertexLayout, MeshGPU& meshGPU);
    void SetVBO(const std::vector<uint8_t> rawVertices, MeshGPU& meshGPU);
    void SetEBO(const std::vector<uint32_t> indices, MeshGPU& meshGPU);
};