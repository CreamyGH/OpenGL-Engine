#pragma once
#include <spdlog/spdlog.h>
#include <csignal>

namespace Core
{
    class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};
}

#ifdef DEBUG
    #define LOG_ENABLE_ASSERTS
#endif

#ifdef _MSC_VER
    #define LOG_DEBUGBREAK() __debugbreak()
#else
    #define LOG_DEBUGBREAK() raise(SIGTRAP)
#endif

#ifdef LOG_ENABLE_ASSERTS
    #define LOG_ASSERT(x, ...) \
        { if(!(x)) { LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); LOG_DEBUGBREAK(); } }
#else
    #define LOG_ASSERT(x, ...)
#endif


#define LOG_TRACE(...)         ::Core::Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)          ::Core::Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)          ::Core::Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)         ::Core::Log::GetLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)      ::Core::Log::GetLogger()->critical(__VA_ARGS__)