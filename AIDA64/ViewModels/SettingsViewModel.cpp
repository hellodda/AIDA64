#include "pch.h"
#include "SettingsViewModel.h"
#if __has_include("SettingsViewModel.g.cpp")
#include "SettingsViewModel.g.cpp"
#endif

#include <Config/ApplicationState.h>
#include <Framework/Utilities.h>
#include <Win32Helpers/BatteryController.h>
#include <winrt/Windows.Storage.h>



namespace winrt::AIDA64::implementation
{
	SettingsViewModel::SettingsViewModel()
	{
		AIDA64::VisualConfiguration acrylic_conf{};
		acrylic_conf.Value(box_value(L"Acrylic"));
		acrylic_conf.ImagePath(L"../Assets/Acrylic.png");
		AIDA64::VisualConfiguration mica_conf{};
		mica_conf.Value(box_value(L"Mica"));
		mica_conf.ImagePath(L"../Assets/Mica.png");
		AIDA64::VisualConfiguration none_conf{};
		none_conf.Value(box_value(L"None"));
		none_conf.ImagePath(L"../Assets/None.png");
		m_backdrops.Append(none_conf);
		m_backdrops.Append(mica_conf);
		m_backdrops.Append(acrylic_conf);
	}
	Windows::Foundation::Collections::IObservableVector<AIDA64::VisualConfiguration> SettingsViewModel::Backdrops() const noexcept
	{
		return m_backdrops;
	}
	void SettingsViewModel::Backdrops(Windows::Foundation::Collections::IObservableVector<AIDA64::VisualConfiguration> const& value)
	{
		if (m_backdrops != value)
		{
			m_backdrops = value;
		}
	}

	void SettingsViewModel::ChangeBackdrop(hstring const& value)
	{
		Windows::Storage::ApplicationData::Current().LocalSettings().Values().Insert(L"Backdrop", box_value(value));

		if (value == L"Acrylic")
		{
			configuration::ApplicationState::Instance().Backdrop(Microsoft::UI::Xaml::Media::DesktopAcrylicBackdrop());
		}
		else if (value == L"Mica")
		{
			configuration::ApplicationState::Instance().Test();
		}
		else
		{
			configuration::ApplicationState::Instance().Backdrop(nullptr);
		}
	}
	void SettingsViewModel::BatterySaveEnabled(bool value)
	{
		Windows::Storage::ApplicationData::Current().LocalSettings().Values().Insert(L"EcoMode", box_value(value));
		
		configuration::ApplicationState::Instance().EcoMode(value);
	}
	bool SettingsViewModel::BatterySaveEnabled() const noexcept
	{
		return configuration::ApplicationState::Instance().EcoMode();
	}
	winrt::ICommand SettingsViewModel::OpenConsoleCommand()
	{
		if (!m_openConsoleCommand)
		{
			m_openConsoleCommand = winrt::make<RelayCommand>([this]() -> IAsyncAction {

				FILE* stream;
				freopen_s(&stream, "CONOUT$", "w", stdout);
				freopen_s(&stream, "CONOUT$", "w", stderr);
				freopen_s(&stream, "CONIN$", "r", stdin);

			
				co_return;
			});
		}
		return m_openConsoleCommand;
	}
}
