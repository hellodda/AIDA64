#include "pch.h"
#include "ApplicationState.h"
#include <Config/ApplicationConfiguration.h>
#include <Win32Helpers/BatteryController.h>
#include <Framework/Utilities.h>
#include <winrt/Microsoft.UI.Composition.SystemBackdrops.h>
#include <winrt/Microsoft.UI.Composition.h>
#include <winrt/Microsoft.UI.Xaml.Media.h>
#include <winrt/Windows.System.h>


namespace winrt::AIDA64::configuration
{
	Windows::Foundation::IAsyncAction ApplicationState::ConfigureApplicationAsync()
	{
		auto backdrop_type = co_await configuration::ApplicationConfiguration::Instance().LoadDataAsync(L"Backdrop");
		auto eco_mode = co_await configuration::ApplicationConfiguration::Instance().LoadDataAsync(L"EcoMode");

		if (backdrop_type == L"Mica")
		{
			configuration::ApplicationState::Instance().Backdrop(Microsoft::UI::Xaml::Media::MicaBackdrop());
		}
		else if (backdrop_type == L"Acrylic")
		{
			configuration::ApplicationState::Instance().Backdrop(Microsoft::UI::Xaml::Media::DesktopAcrylicBackdrop());
		}
		else
		{
			configuration::ApplicationState::Instance().Backdrop(nullptr);
		}
		EcoMode(to_bool(winrt::to_string(eco_mode)));
	}
	Windows::Foundation::IAsyncAction ApplicationState::ConfigureApplicationAsync(std::function<Windows::Foundation::IAsyncAction(ApplicationState&)> schema)
	{
		co_await schema(*this);
	}
	Microsoft::UI::Xaml::Window ApplicationState::Window() const noexcept
	{
		return m_window;
	}
	void ApplicationState::Window(Microsoft::UI::Xaml::Window const& value)
	{
		if (m_window != value)
		{
			m_window = value;
		}
	}
	bool ApplicationState::EcoMode() const noexcept
	{
		return m_ecoEnabled;
	}
	void ApplicationState::EcoMode(bool value)
	{
		m_ecoEnabled = value;

		if (m_ecoEnabled)
		{
			win32::BatteryController::Instance().EnableEcoMode();
		}
		else
		{
			win32::BatteryController::Instance().DisableEcoMode();
		}
	}
	Microsoft::UI::Xaml::Media::SystemBackdrop ApplicationState::Backdrop() const noexcept
	{
		return m_backdrop;
	}
	void ApplicationState::Backdrop(Microsoft::UI::Xaml::Media::SystemBackdrop const& value)
	{
		if (!m_window)
			throw std::runtime_error("Window is null!");

		if (m_backdrop != value)
		{
			m_backdrop = value;
			m_window.SystemBackdrop(m_backdrop);
		}
	}
	void ApplicationState::Test()
	{
		auto dispatcherQueue = winrt::Microsoft::UI::Dispatching::DispatcherQueue::GetForCurrentThread();
		auto windowNative = m_window.as<winrt::Microsoft::UI::Composition::ICompositionSupportsSystemBackdrop>();


		if (winrt::Microsoft::UI::Composition::SystemBackdrops::MicaController::IsSupported())
		{
			m_micaController = winrt::Microsoft::UI::Composition::SystemBackdrops::MicaController();
			m_backdropConfiguration = winrt::Microsoft::UI::Composition::SystemBackdrops::SystemBackdropConfiguration();

			m_backdropConfiguration.IsInputActive(true);
			m_backdropConfiguration.Theme(winrt::Microsoft::UI::Composition::SystemBackdrops::SystemBackdropTheme::Default);

			m_micaController.Kind(winrt::Microsoft::UI::Composition::SystemBackdrops::MicaKind::BaseAlt); 
			m_micaController.AddSystemBackdropTarget(windowNative);
			m_micaController.SetSystemBackdropConfiguration(m_backdropConfiguration);
		}
	}
}