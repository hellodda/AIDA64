#include "pch.h"
#include "SettingsPage.xaml.h"
#if __has_include("SettingsPage.g.cpp")
#include "SettingsPage.g.cpp"
#endif

#include "App.xaml.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;


namespace winrt::AIDA64::implementation
{
	SettingsPage::SettingsPage()
	{
	
	}

	void SettingsPage::OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
	{
		if (auto param = e.Parameter().try_as<AIDA64::SettingsViewModel>())
		{
			m_viewmodel = param;
		}
	}
	AIDA64::SettingsViewModel SettingsPage::ViewModel()
	{
		return m_viewmodel;
	}
}

void winrt::AIDA64::implementation::SettingsPage::BackdropsCollection_ItemClick(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::ItemClickEventArgs const& e)
{
	auto clickedItem = e.ClickedItem().as<AIDA64::VisualConfiguration>();

	m_viewmodel.ChangeBackdrop(winrt::unbox_value<hstring>(clickedItem.Value()));
}

void winrt::AIDA64::implementation::SettingsPage::ToggleSwitch_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
	auto sender_obj = sender.as<Microsoft::UI::Xaml::Controls::ToggleSwitch>();
	m_viewmodel.as<implementation::SettingsViewModel>()->BatterySaveEnabled(sender_obj.IsOn());
}
