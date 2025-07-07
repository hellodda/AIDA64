#include "pch.h"
#include "VisualConfiguration.h"
#if __has_include("VisualConfiguration.g.cpp")
#include "VisualConfiguration.g.cpp"
#endif

namespace winrt::AIDA64::implementation
{
	winrt::hstring VisualConfiguration::ImagePath() const noexcept
	{
		return m_imagePath;
	}

	void VisualConfiguration::ImagePath(winrt::hstring const& value)
	{
		if (m_imagePath != value)
		{
			m_imagePath = value;
		}
	}

	winrt::hstring VisualConfiguration::Value() const noexcept
	{
		return m_value;
	}

	void VisualConfiguration::Value(winrt::hstring const& value)
	{
		if (m_value != value)
		{
			m_value = value;
		}
	}
}
