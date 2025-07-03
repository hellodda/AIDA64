#pragma once
#include "ICpuService.h"
#include "ILogger.h"

#include <Models/CpuModel.h>
#include <Wmi/IWmiDataContext.h>


namespace winrt::AIDA64::Framework
{
    struct CpuService : ICpuService
    {
        CpuService(std::shared_ptr<wmi::IWmiDataContext> context, std::shared_ptr<ILogger> logger);

        Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<AIDA64::CpuModel>>GetCpuInformationAsync() override;

    private:
        std::shared_ptr<wmi::IWmiDataContext> m_context;
        std::shared_ptr<ILogger> m_logger;
    };
}
