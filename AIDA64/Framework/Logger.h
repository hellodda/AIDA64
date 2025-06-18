#pragma once
#include <Framework/ILogger.h>

namespace winrt::AIDA64::Framework
{
	struct Logger : public ILogger
	{
		void log_info(std::string message) override;
		void log_error(std::string message) override;
		void log_critical(std::string message) override;
		void log_warning(std::string message) override;
	};
}

