#include "Log.h"

#include "cassert"

int main() 
{
    Core::Log::Init();

    LOG_INFO("info");
    LOG_WARN("warn");
    LOG_CRITICAL("critical");
    LOG_TRACE("trace");
}