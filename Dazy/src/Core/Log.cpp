#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Dazy
{
	Ref<spdlog::logger> Logger::coreLogger;
	Ref<spdlog::logger> Logger::defaultLogger;

	void Logger::Init()
	{
		std::vector<spdlog::sink_ptr> logSinks;
		logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Dazy.log", true));

		logSinks[0]->set_pattern("%^[%T] %n: %v%$");
		logSinks[1]->set_pattern("[%T] [%l] %n: %v");

		coreLogger = std::make_shared<spdlog::logger>("Dazy", begin(logSinks), end(logSinks));
		spdlog::register_logger(coreLogger);

		defaultLogger = std::make_shared<spdlog::logger>("APP", begin(logSinks), end(logSinks));
		spdlog::register_logger(defaultLogger);

#ifdef _DEBUG
		coreLogger->set_level(spdlog::level::trace);
		coreLogger->flush_on(spdlog::level::trace);

		defaultLogger->set_level(spdlog::level::trace);
		defaultLogger->flush_on(spdlog::level::trace);
#else
		coreLogger->set_level(spdlog::level::info);
		coreLogger->flush_on(spdlog::level::info);

		defaultLogger->set_level(spdlog::level::info);
		defaultLogger->flush_on(spdlog::level::info);
#endif
	}
}