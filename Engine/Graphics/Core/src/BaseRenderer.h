#pragma once

#include <memory>
#include "RenderPass.h"

class Renderer
{
friend class Singleton<Renderer>;

public:
    inline void Init()
    {
        InitSSBOs();
        setupRenderQueue();
    }

    inline void Destroy()
    {
        DeleteSSBOs();   
    } 

    virtual void BeginFrame(FrameData& frameData) = 0; //Send frame data to GPU and clear data
    virtual void RenderFrame(FrameData& frameData) = 0; //Iterate through render passes passing frame data to each pass
    virtual void EndFrame(FrameData& frameData) = 0; //Post process execute with filled framedata

    virtual ~Renderer() = default;
    
protected:
    void AddRenderPass(std::unique_ptr<RenderPass> pass) { m_RenderQueue.emplace_back(std::move(pass)); }
    virtual void setupRenderQueue() = 0;

    virtual void InitSSBOs() {};
    virtual void DeleteSSBOs() {};

protected:
    std::vector<std::unique_ptr<RenderPass>> m_RenderQueue;
};