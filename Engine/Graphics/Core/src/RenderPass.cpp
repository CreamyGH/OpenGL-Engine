#include "RenderPass.h"

void RenderPass::EnableOffScreenRendering(int width, int height)
{
    GenerateFrameBuffer();
    BindFrameBuffer();
    SetupFBOAttachments(width, height);
    UnBindFrameBuffer();

    Core::EventManager::get().AddListenerFunc<Core::WindowResizeEvent>(BIND_EVENT_FN(OnResize));
}

bool RenderPass::OnResize(Core::WindowResizeEvent &event)
{
    BindFrameBuffer();
    SetupFBOAttachments((int)event.width, (int)event.height);
    UnBindFrameBuffer();
    return false;
}   

RenderPass::~RenderPass()
{
    DeleteFrameBuffer();
}