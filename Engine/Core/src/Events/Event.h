#pragma once
#include "../pch.h"

namespace Core
{
    using EventTypeID       = uint32_t;   
    using EventCategoryMask = uint32_t;   
    
    
    #define EVENT_CLASS_TYPE(ID_CONST, NAME_LITERAL)                                  \
        static constexpr EventTypeID StaticType() { return (ID_CONST); }              \
        EventTypeID GetType() const override { return StaticType(); }                 \
        const char* GetName() const override { return (NAME_LITERAL); }
    
    
    #define EVENT_CLASS_CATEGORY(MASK_EXPR)                                         \
        EventCategoryMask GetCategoryMask() const override { return (MASK_EXPR); }
    
    
    class Event 
    {
    public:
        virtual ~Event() = default;
    
        bool Handled = false;
    
        virtual EventTypeID GetType() const = 0;  
        virtual const char* GetName() const = 0;
        virtual EventCategoryMask GetCategoryMask() const = 0;
        virtual std::string LogInfo() const = 0;
    
    
        bool IsInCategory(EventCategoryMask mask) const {
            return (GetCategoryMask() & mask) != 0;
        }
    };
}

