#pragma once

#include "AiPage.g.h"

namespace winrt::AIDA64::implementation
{
    struct AiPage : AiPageT<AiPage>
    {
        AiPage();
        void OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);
        AIDA64::AiPageViewModel ViewModel();

    private:
        AIDA64::AiPageViewModel m_viewmodel;
    public:
        void Page_KeyDown(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::KeyRoutedEventArgs const& e);
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct AiPage : AiPageT<AiPage, implementation::AiPage>
    {
    };
}
