#include "pch.h"
#include "CpuService.h"

#include <Wmi/WmiMapping.h>

inline constexpr const wchar_t* QUERY_PROCESSOR_LIST = L"SELECT * FROM Win32_Processor";

namespace winrt::AIDA64::Framework
{
    CpuService::CpuService(std::shared_ptr<wmi::IWmiDataContext> context, std::shared_ptr<ILogger> logger)
        : m_context(std::move(context)), m_logger(std::move(logger)) {}

    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<AIDA64::CpuModel>>CpuService::GetCpuInformationAsync()
    {
        co_await winrt::resume_background();

        m_logger->log_info("YEEEEEEEEEEEEEEEEEEEEEEEEEE");

        auto result = co_await m_context->QueryAsync(QUERY_PROCESSOR_LIST);

        auto models = winrt::single_threaded_vector<AIDA64::CpuModel>();

        for (auto const& wmo : result)
        {
            auto model = wmi::from_wmi<AIDA64::CpuModel>(wmo);
            models.Append(model);
            m_logger->log_info("cpu model lp: " + std::to_string(model.LoadPercentage()));
        }

        co_return models;
    }
}