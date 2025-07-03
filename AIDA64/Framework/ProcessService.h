#pragma once
#include "IProcessService.h"
#include <Wmi/IWmiDataContext.h>

namespace winrt::AIDA64::Framework
{
    struct ProcessService : IProcessService
    {
        ProcessService(std::shared_ptr<IWmiDataContext> context);

        Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<AIDA64::ProcessModel>>GetAllProcessesAsync() override;

    private:
        std::shared_ptr<IWmiDataContext> m_context;
    };
}