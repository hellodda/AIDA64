#pragma once

#include "DisplayPage.g.h"

#include <ViewModels/DisplayPageViewModel.h>

namespace winrt
{
    using namespace AIDA64;
}

namespace winrt::AIDA64::implementation
{
    struct DisplayPage : DisplayPageT<DisplayPage>
    {
        DisplayPage();

        void OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);

        winrt::DisplayPageViewModel ViewModel();

    private:

        winrt::DisplayPageViewModel m_viewmodel{};
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct DisplayPage : DisplayPageT<DisplayPage, implementation::DisplayPage>
    {
    };
}
