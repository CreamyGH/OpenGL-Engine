#pragma once
#include "Event.h"
#include "CoreEvents.h"

namespace Core
{
    // class WindowResizeEvent : public Event
    // {
    // public:
    //     WindowResizeEvent(uint32_t width, uint32_t height)
    //         : m_Width(width), m_Height(height) {}

    //     inline uint32_t GetWidth() const { return m_Width; }
    //     inline uint32_t GetHeight() const { return m_Height; }

    //     const std::string LogInfo() const override
    //     {
    //         std::stringstream ss;
    //         ss << "Width, Height: " << m_Width << ", " << m_Height;
    //         return ss.str();
    //     }

    //     EVENT_CLASS_TYPE(EventTypes::WindowResize, "WindowResize")
    //     EVENT_CLASS_CATEGORY(EventCategories::Window)
    // private:
    //     uint32_t m_Width, m_Height;
    // };

    // class WindowCloseEvent : public Event
    // {
    // public:
    //     WindowCloseEvent() {}


    //     const std::string LogInfo() const override
    //     {
    //         std::stringstream ss;
    //         ss << "Closed!";
    //         return ss.str();
    //     }

    //     EVENT_CLASS_TYPE(WindowClose)
    //     EVENT_CLASS_CATEGORY(EventCategoryWindow)
    // };


    class WindowResizeEvent : public Event 
    {
    public:
        WindowResizeEvent(uint32_t w, uint32_t h) : width(w), height(h) {}

        EVENT_CLASS_TYPE(EventTypes::WindowResized, "WindowResized")
        EVENT_CLASS_CATEGORY(EventCategories::Window)

        std::string LogInfo() const override 
        {
            std::stringstream ss;
            ss << "Width, Height: " << width << ", " << height;
            return ss.str();
        }

        uint32_t width = 0, height = 0;
    };

    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() = default;

        EVENT_CLASS_TYPE(EventTypes::WindowClosed, "WindowClosed")
        EVENT_CLASS_CATEGORY(EventCategories::Window)

        std::string LogInfo() const override
        {
            std::stringstream ss;
            ss << "Closed!";
            return ss.str();
        }
    };
}

