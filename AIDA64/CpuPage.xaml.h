#pragma once

#include "CpuPage.g.h"

namespace winrt::AIDA64::implementation
{
    struct CpuPage : CpuPageT<CpuPage>
    {
        CpuPage()
        {
            
        }
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct CpuPage : CpuPageT<CpuPage, implementation::CpuPage>
    {
    };
}
