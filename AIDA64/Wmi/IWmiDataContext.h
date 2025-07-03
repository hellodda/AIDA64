#pragma once
#include <async/task.h>
#include "WmiObject.h"

namespace wmi
{
	struct IWmiDataContext
	{
		virtual std::vector<wmi::WmiObject> Query(_bstr_t const& query) = 0;
		virtual async::task<std::vector<wmi::WmiObject>> QueryAsync(_bstr_t const query) = 0;
	};

	namespace variables
	{
		inline constexpr const wchar_t* STANDART_NAMESPACE = L"ROOT\\CIMV2";
		inline constexpr const wchar_t* QUERY_PROCESSOR_LIST = L"SELECT * FROM Win32_Processor";
		inline constexpr const wchar_t* QUERY_DISPLAY_LIST = L"SELECT * FROM Win32_DesktopMonitor";
		inline constexpr const wchar_t* QUERY_PROCESS_LIST = L"SELECT * FROM Win32_Process";
		inline constexpr const wchar_t* AIDA64_VERSION = L"0.0.1alpha :)";
	}
}