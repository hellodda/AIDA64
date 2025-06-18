#pragma once

namespace winrt::AIDA64::Framework
{
	struct ILogger
	{
		virtual void log_info(std::string message) = 0;
		virtual void log_error(std::string message) = 0;
		virtual void log_critical(std::string message) = 0;
		virtual void log_warning(std::string message) = 0;
	};
}

