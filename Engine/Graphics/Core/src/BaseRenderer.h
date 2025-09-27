#pragma once

#include <memory>
#include "RenderPass.h"

class Renderer
{
public:
    inline void Init()
    {
        SetupRenderQueue();
    }

    virtual void BeginFrame(FrameData& frameData) = 0; //Send frame data to GPU and clear data
    virtual void RenderFrame(FrameData& frameData) = 0; //Iterate through render passes passing frame data to each pass
    virtual void EndFrame(FrameData& frameData) = 0; //Post process execute with filled framedata

    virtual ~Renderer() = default;
    
protected:
    void AddRenderPass(std::unique_ptr<RenderPass> pass) { m_RenderQueue.emplace_back(std::move(pass)); }
    virtual void SetupRenderQueue() = 0;

protected:
    std::vector<std::unique_ptr<RenderPass>> m_RenderQueue;
};