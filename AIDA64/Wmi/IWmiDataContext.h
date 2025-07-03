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
        inline constexpr const wchar_t* NAMESPACE_ROOT_WMI = L"ROOT\\WMI";
        inline constexpr const wchar_t* NAMESPACE_ROOT_CIMV2 = L"ROOT\\CIMV2";
        inline constexpr const wchar_t* DEFAULT_NAMESPACE = NAMESPACE_ROOT_CIMV2;

        inline constexpr const wchar_t* QUERY_WIN32_PROCESSOR = L"SELECT * FROM Win32_Processor";
        inline constexpr const wchar_t* QUERY_WIN32_PROCESS = L"SELECT * FROM Win32_Process";
        inline constexpr const wchar_t* QUERY_WIN32_DESKTOP_MONITOR = L"SELECT * FROM Win32_DesktopMonitor";
        inline constexpr const wchar_t* QUERY_ACPI_THERMAL_TEMPERATURE = L"SELECT CurrentTemperature FROM MSAcpi_ThermalZoneTemperature";
        inline constexpr const wchar_t* QUERY_WIN32_FAN = L"SELECT * FROM Win32_Fan";
    }

}