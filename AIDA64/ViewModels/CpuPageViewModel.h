#pragma once

#include "CpuPageViewModel.g.h"

namespace winrt::AIDA64::implementation
{
    struct CpuPageViewModel : CpuPageViewModelT<CpuPageViewModel>
    {
        CpuPageViewModel() = default;
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct CpuPageViewModel : CpuPageViewModelT<CpuPageViewModel, implementation::CpuPageViewModel>
    {
    };
}
