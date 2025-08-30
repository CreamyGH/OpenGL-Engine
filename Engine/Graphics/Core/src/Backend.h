#pragma once

#include "BaseRenderer.h"
#include "MeshUploader.h"

class Backend
{
public:

    virtual void InitBackend() = 0;
    virtual void InitRenderers() = 0;

    const std::unique_ptr<Renderer> GetRenderer(const std::string& name);

    virtual const std::unique_ptr<MeshUploader> GetMeshUploader() = 0;
    //virtual const std::unique_ptr<ShaderCache> GetShaderCache() = 0;
    //virtual const std::unique_ptr<PipelineStateBuilder> GetPipelineStateBuilder() = 0;
    
protected:
    void AddRenderer(const std::string& name, std::unique_ptr<Renderer> renderer) {
        m_NameToRenderer.emplace(name, std::move(renderer));
    }

private:
    std::unordered_map<std::string, std::unique_ptr<Renderer>> m_NameToRenderer;

};