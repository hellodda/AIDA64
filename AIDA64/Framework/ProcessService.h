#pragma once
#include "IProcessService.h"
#include "ILogger.h"

#include <Wmi/IWmiDataContext.h>

namespace winrt::AIDA64::Framework
{
    struct ProcessService : IProcessService
    {
        ProcessService(std::shared_ptr<wmi::IWmiDataContext> context, std::shared_ptr<ILogger> logger);

        Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<AIDA64::ProcessModel>>GetAllProcessesAsync() override;

    private:
        std::shared_ptr<wmi::IWmiDataContext> m_context;
        std::shared_ptr<ILogger> m_logger;
    };
}