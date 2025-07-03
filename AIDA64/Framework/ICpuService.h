#pragma once
#include <Models/CpuModel.h>

namespace winrt::AIDA64::Framework
{
    struct ICpuService
    {
        virtual Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<AIDA64::CpuModel>>GetCpuInformationAsync() = 0;
    };
}
