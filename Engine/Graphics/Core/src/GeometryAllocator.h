#pragma once

#include <memory>

#include "MeshGPU.h"
#include "VertexLayout.h"
#include "MeshUploadData.h"

class GeometryAllocator
{
public:
    virtual ~GeometryAllocator() = default;

    virtual std::unique_ptr<MeshGPU> UploadMeshStatic(const MeshUploadData* meshData) = 0;

    virtual std::unique_ptr<MeshGPU> UploadMeshesStatic(
        const std::vector<std::unique_ptr<MeshUploadData>>& meshDataArr) = 0;


    virtual std::unique_ptr<MeshGPU> UploadMeshDynamic(const MeshUploadData* meshData) = 0;

    virtual std::unique_ptr<MeshGPU> UploadMeshesDynamic(
        const std::vector<std::unique_ptr<MeshUploadData>>& meshDataArr) = 0;
};