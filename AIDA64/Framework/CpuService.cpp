#include "pch.h"
#include "CpuService.h"
#include "Utilities.h"

constexpr wchar_t* QUERY_PROCESSOR_LIST = L"SELECT * FROM Win32_Processor";

namespace winrt::AIDA64::Framework
{
	CpuService::CpuService(std::shared_ptr<WmiDataContext> context)
	{
        m_context = std::move(context);
	}
	IAsyncOperation<IVector<ProcessorModel>> CpuService::GetAllProcessorsAsync()
    { 
        winrt::resume_background();

        std::vector<com_ptr<IWbemClassObject>> result;

        co_await m_context->QueryAsync(QUERY_PROCESSOR_LIST, result);

        auto models = single_threaded_vector<ProcessorModel>();

        for (auto const& object : result)
        {
            ProcessorModel model = from_wbem<ProcessorModel>(object);
            models.Append(model);
        }

        co_return models;
	}
}