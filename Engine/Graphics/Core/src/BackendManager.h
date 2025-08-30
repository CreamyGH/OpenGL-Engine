#pragma once

#include <memory>

#include "Backend.h"
#include "Helpers/Singleton.h"

class BackendManager : public Singleton<BackendManager> 
{
    friend class Singleton<BackendManager>;
public:
    void SetBackend(std::unique_ptr<Backend> backend) 
    {
        if (!backend) 
        {
            LOG_ASSERT(false, "SetBackend called with null");
            return;
        }
        m_CurrentBackend = std::move(backend);
        m_Initialized = false; 
    }

    void InitBackend() 
    {
        RequireBackend();                
        m_CurrentBackend->InitBackend(); 
        m_CurrentBackend->InitRenderers();
        m_Initialized = true;
    }

    Backend& GetBackend() 
    {
        RequireBackend();
        return *m_CurrentBackend;
    }

    const Backend& GetBackend() const 
    {
        RequireBackend();
        return *m_CurrentBackend;
    }

    bool HasBackend() const noexcept { return static_cast<bool>(m_CurrentBackend); }
    bool IsInitialized() const noexcept { return m_Initialized; }

private:
    void RequireBackend() const {
        LOG_ASSERT(m_CurrentBackend, "Backend not set – call SetBackend() first");
    }

private:
    std::unique_ptr<Backend> m_CurrentBackend;
    bool m_Initialized = false;
};
