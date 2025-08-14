#pragma once

#include <memory>

#include "Helpers/Singleton.h"
#include "RenderPass.h"

class Renderer : public Singleton<Renderer>
{
friend class Singleton<Renderer>;

public:
    virtual void BeginFrame(FrameData& frameData) = 0; //Send frame data to GPU and clear data
    virtual void RenderFrame(FrameData& frameData) = 0; //Iterate through render passes passing frame data to each pass
    virtual void EndFrame(FrameData& frameData) = 0; //Post process execute with filled framedata

protected:
    void AddRenderPass(std::unique_ptr<RenderPass> pass) { m_RenderQueue.emplace_back(std::move(pass)); }
    virtual void setupRenderQueue() = 0;

    virtual void InitSSBOs() {};
    virtual void DeleteSSBOs() {};
    virtual ~Renderer()
    {
        DeleteSSBOs();
    }

protected:
    std::vector<std::unique_ptr<RenderPass>> m_RenderQueue;

private:
    Renderer()
    {
        InitSSBOs();
        setupRenderQueue();
    }
};