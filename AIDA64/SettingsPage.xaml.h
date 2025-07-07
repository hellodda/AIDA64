#pragma once

#include "SettingsPage.g.h"

namespace winrt::AIDA64::implementation
{
    struct SettingsPage : SettingsPageT<SettingsPage>
    {
        SettingsPage();

        void OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);
        AIDA64::SettingsViewModel ViewModel();

    private:
        AIDA64::SettingsViewModel m_viewmodel;
    public:
        void BackdropsCollection_ItemClick(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::ItemClickEventArgs const& e);
        winrt::Microsoft::UI::Xaml::Window m_window{ nullptr };
        void ToggleSwitch_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct SettingsPage : SettingsPageT<SettingsPage, implementation::SettingsPage>
    {
    };
}
