#include "pch.h"
#include "MemoryService.h"

#include <Wmi/WmiMapping.h>


namespace winrt::AIDA64::Framework
{
	MemoryService::MemoryService(std::shared_ptr<wmi::IWmiDataContext> context, std::shared_ptr<ILogger> logger)
		: m_context(std::move(context)), m_logger(std::move(logger)) {};

	Windows::Foundation::IAsyncOperation<AIDA64::MemoryModel> MemoryService::GetMemoryInformationAsync()
	{
		if (!m_context || !m_logger) throw hresult_error(E_FAIL, L"Context or Logger is Null!");

		co_await winrt::resume_background();

		auto result = co_await m_context->QueryAsync(wmi::variables::QUERY_WIN32_PHYSICAL_MEMORY);

		AIDA64::MemoryModel model{};

		for (auto const& wmo : result)
		{
			model = wmi::from_wmi<AIDA64::MemoryModel>(wmo);
		}
		co_return model;
	}

}

