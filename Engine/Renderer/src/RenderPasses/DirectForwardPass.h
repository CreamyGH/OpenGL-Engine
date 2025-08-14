#pragma once

#include "../RenderPass.h"

class DirectForwardPass : public RenderPass
{
protected:
    void DrawFrame(FrameData& frameData) override;
};