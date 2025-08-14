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

void RenderPass::GenerateFrameBuffer() {
    glGenFramebuffers(1, &m_FBO);
}


void RenderPass::DeleteFrameBuffer() {
    glDeleteFramebuffers(1, &m_FBO);
}


void RenderPass::BindFrameBuffer() 
{
    glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);
    LOG_ASSERT(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE, "Frame buffer failed to bind");
}


void RenderPass::UnBindFrameBuffer() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void RenderPass::ApplyPipelineState(const PipelineState &state)
{
    //TODO
}

RenderPass::~RenderPass()
{
    DeleteFrameBuffer();
}