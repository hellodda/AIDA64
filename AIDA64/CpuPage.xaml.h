#pragma once

#include "CpuPage.g.h"

#include <ViewModels/CpuPageViewModel.h>

namespace winrt
{
    using namespace AIDA64;
}

namespace winrt::AIDA64::implementation
{
    struct CpuPage : CpuPageT<CpuPage>
    {
        CpuPage();

        void OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);

        winrt::CpuPageViewModel ViewModel();

    private:

        winrt::CpuPageViewModel m_viewModel;

    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct CpuPage : CpuPageT<CpuPage, implementation::CpuPage>
    {
    };
}
