#pragma once

#include <glad/glad.h>
#include "BaseRenderer.h"

class GLDirectRenderer : public Renderer
{
public:
    void BeginFrame(FrameData& frameData) override; //Send frame data to GPU and clear data
    void RenderFrame(FrameData& frameData) override; //Iterate through render passes passing frame data to each pass
    void EndFrame(FrameData& frameData) override; //Post process execute with filled framedata

protected:
    void setupRenderQueue() override;
    void InitSSBOs() override;
    void DeleteSSBOs() override;

private:
    ~GLDirectRenderer() override {};

private:
    GLuint m_CameraUBO = 0;
};