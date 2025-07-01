#include "pch.h"
#include "CpuService.h"
#include "Utilities.h"

inline constexpr const wchar_t* QUERY_PROCESSOR_LIST = L"SELECT * FROM Win32_Processor";

namespace winrt::AIDA64::Framework
{
	CpuService::CpuService(std::shared_ptr<IDataContext> context, std::shared_ptr<ILogger> logger)
	{
        m_context = std::move(context);
        m_logger = std::move(logger);
	}
	IAsyncOperation<IVector<CpuModel>> CpuService::GetCpuInformationAsync()
    { 
        co_await winrt::resume_background();

        m_logger->log_info("YEEEEEEEEEEEEEEEEEEEEEEEEEE");

        auto result = co_await m_context->QueryAsync(QUERY_PROCESSOR_LIST);

        auto models = single_threaded_vector<CpuModel>();

        for (auto const& object : result)
        {
            auto model = from_wmi<CpuModel>(object);
            models.Append(model);
        }

        co_return models;
	}
}