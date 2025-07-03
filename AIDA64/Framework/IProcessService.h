#pragma once
#include <Models/ProcessModel.h>

namespace winrt::AIDA64::Framework
{
    struct IProcessService
    {
        virtual Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<AIDA64::ProcessModel>>GetAllProcessesAsync() = 0;
    };
}