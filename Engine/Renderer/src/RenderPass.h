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
        //TODO ApplyPipelineState(state)
        DrawFrame(frameData);
        UnBindFrameBuffer();
    }

protected:
    virtual void SetupFBOAttachments(int width, int height) {}
    virtual void DrawFrame(FrameData& frameData) = 0;

protected:
    GLuint m_FBO = 0; //default back buffer

private:
    void GenerateFrameBuffer();
    void DeleteFrameBuffer();
    bool OnResize(Core::WindowResizeEvent& event);

    void BindFrameBuffer();
    void UnBindFrameBuffer();
    void ApplyPipelineState(const PipelineState& state);
};