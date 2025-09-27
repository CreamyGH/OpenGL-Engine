#pragma once

#include <glad/glad.h>
#include "BaseRenderer.h"

class GLDirectRenderer : public Renderer
{
public:
    ~GLDirectRenderer() override;

    void BeginFrame(FrameData& frameData) override; //Send frame data to GPU and clear data
    void RenderFrame(FrameData& frameData) override; //Iterate through render passes passing frame data to each pass
    void EndFrame(FrameData& frameData) override; //Post process execute with filled framedata
    
protected:
    void SetupRenderQueue() override;
    
private:
    GLuint m_CameraUBO = 0;
};