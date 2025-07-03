#pragma once
#include <Models/DisplayModel.h>

namespace winrt::AIDA64::Framework
{
    struct IDisplayService
    {
        virtual Windows::Foundation::IAsyncOperation<AIDA64::DisplayModel>GetDisplayInformationAsync() = 0;
    };
}
