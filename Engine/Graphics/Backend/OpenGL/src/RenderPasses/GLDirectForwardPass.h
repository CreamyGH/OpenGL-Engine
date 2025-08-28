#pragma once

#include <glad/glad.h>
#include "RenderPass.h"

class GLDirectForwardPass : public RenderPass
{
protected:
    void DrawFrame(FrameData& frameData) override;
};