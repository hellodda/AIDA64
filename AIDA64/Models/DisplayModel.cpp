#include "pch.h"
#include "DisplayModel.h"
#if __has_include("DisplayModel.g.cpp")
#include "DisplayModel.g.cpp"
#endif

namespace winrt::AIDA64::implementation
{
	hstring DisplayModel::Name() const noexcept { return m_name; }
	void DisplayModel::Name(hstring const& value)
	{
		if (m_name != value) m_name = value;
	}

	hstring DisplayModel::DeviceId() const noexcept { return m_deviceId; }
	void DisplayModel::DeviceId(hstring const& value)
	{
		if (m_deviceId != value) m_deviceId = value;
	}

	hstring DisplayModel::MonitorType() const noexcept { return m_monitorType; }
	void DisplayModel::MonitorType(hstring const& value)
	{
		if (m_monitorType != value) m_monitorType = value;
	}

	uint32_t DisplayModel::ScreenHeight() const noexcept { return m_screenHeight; }
	void DisplayModel::ScreenHeight(uint32_t const& value)
	{
		if (m_screenHeight != value) m_screenHeight = value;
	}

	uint32_t DisplayModel::ScreenWidth() const noexcept { return m_screenWidth; }
	void DisplayModel::ScreenWidth(uint32_t const& value)
	{
		if (m_screenWidth != value) m_screenWidth = value;
	}
}
