#pragma once
#include "Base.h"

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Dazy
{
	using LogLevel = spdlog::level::level_enum;

	class Logger
	{
	public:
		static void Init();
		static Ref<spdlog::logger>& GetCore()	{ return coreLogger; }
		static Ref<spdlog::logger>& Get()		{ return defaultLogger; }

	private:
		static Ref<spdlog::logger> coreLogger;
		static Ref<spdlog::logger> defaultLogger;
	};
}

// Core logger
#ifdef _DEBUG
	#define LOG_CORE_TRACE(...)    ::Dazy::Logger::GetCore()->trace(__VA_ARGS__)
	#define LOG_CORE_DEBUG(...)    ::Dazy::Logger::GetCore()->debug(__VA_ARGS__)
#else
	#define LOG_CORE_TRACE(...) ((void)0)
	#define LOG_CORE_DEBUG(...) ((void)0)
#endif

#define LOG_CORE_INFO(...)		::Dazy::Logger::GetCore()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)		::Dazy::Logger::GetCore()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...)		::Dazy::Logger::GetCore()->error(__VA_ARGS__)
#define LOG_CORE_CRITICAL(...)	::Dazy::Logger::GetCore()->critical(__VA_ARGS__)

#define LOG_CORE(level, ...)	::Dazy::Logger::GetCore()->log(level, __VA_ARGS__)

// Default logger
#ifdef _DEBUG
	#define LOG_TRACE(...)    ::Dazy::Logger::Get()->trace(__VA_ARGS__)
	#define LOG_DEBUG(...)    ::Dazy::Logger::Get()->debug(__VA_ARGS__)
#else
	#define LOG_TRACE(...) ((void)0)
	#define LOG_DEBUG(...) ((void)0)
#endif

#define LOG_INFO(...)		::Dazy::Logger::Get()->info(__VA_ARGS__)
#define LOG_WARN(...)		::Dazy::Logger::Get()->warn(__VA_ARGS__)
#define LOG_ERROR(...)		::Dazy::Logger::Get()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)	::Dazy::Logger::Get()->critical(__VA_ARGS__)

#define LOG(level, ...)		::Dazy::Logger::Get()->log(level, __VA_ARGS__)