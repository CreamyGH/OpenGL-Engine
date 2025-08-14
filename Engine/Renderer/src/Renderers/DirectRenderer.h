#pragma once

#include "../BaseRenderer.h"

class DirectRenderer : public Renderer
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
    ~DirectRenderer() override {};

private:
    GLuint m_CameraUBO = 0;
};