#pragma once
#include <winrt/Windows.Data.Json.h>
#include <winrt/Windows.Storage.h>

namespace winrt::AIDA64::configuration
{
	struct ApplicationConfiguration
	{
		static ApplicationConfiguration& Instance();

		winrt::Windows::Foundation::IAsyncOperation<hstring> LoadDataAsync(hstring const& key) const;
		winrt::Windows::Foundation::IAsyncAction SaveDataAsync(hstring const& key, hstring const& value);

	private:

		winrt::hstring m_configFileName{ L"config.json" };
	};
}