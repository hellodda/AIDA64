#pragma once

#include "MemoryPage.g.h"

#include <ViewModels/MemoryPageViewModel.h>

namespace winrt::AIDA64::implementation
{
    struct MemoryPage : MemoryPageT<MemoryPage>
    {
        MemoryPage();

        void OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);

        AIDA64::MemoryPageViewModel ViewModel() const noexcept;

    private:

        AIDA64::MemoryPageViewModel m_viewmodel;
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct MemoryPage : MemoryPageT<MemoryPage, implementation::MemoryPage>
    {
    };
}
