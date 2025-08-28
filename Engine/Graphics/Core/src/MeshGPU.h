#pragma once

struct MeshGPU
{
    virtual ~MeshGPU() = default;

    virtual void Bind() = 0;
    virtual void UnBind() = 0;
};