#pragma once

#include "FrameData.h"

#include "Events/EventManager.h"
#include "Events/WindowEvent.h"

class RenderPass
{
public:
    ~RenderPass();

    void EnableOffScreenRendering(int width, int height);

    inline void Execute(FrameData& frameData)
    {
        BindFrameBuffer();
        DrawFrame(frameData);
        UnBindFrameBuffer();
    }

protected:
    virtual void DrawFrame(FrameData& frameData) = 0;
    virtual void SetupFBOAttachments(int width, int height) {}

    virtual void GenerateFrameBuffer() {}
    virtual void DeleteFrameBuffer() {}
    
    virtual void BindFrameBuffer() {};
    virtual void UnBindFrameBuffer() {};
    
private:
    bool OnResize(Core::WindowResizeEvent& event);
};