#include "pch.h"
#include "Logger.h"
#include <spdlog/spdlog.h>


namespace winrt::AIDA64::Framework
{
	void Logger::log_info(std::string message)
	{
		spdlog::info(message);
	}

	void Logger::log_error(std::string message)
	{
		spdlog::error(message);
	}

	void Logger::log_critical(std::string message)
	{
		spdlog::critical(message);
	}

	void Logger::log_warning(std::string message)
	{
		spdlog::warn(message);
	}
}
