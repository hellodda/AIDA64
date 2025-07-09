#pragma once
#include "IMemoryService.h"
#include <Wmi/WmiDataContext.h>
#include "ILogger.h"

namespace winrt::AIDA64::Framework
{
	struct MemoryService : IMemoryService
	{
		MemoryService(std::shared_ptr<wmi::IWmiDataContext> context, std::shared_ptr<ILogger> logger);

		Windows::Foundation::IAsyncOperation<AIDA64::MemoryModel> GetMemoryInformationAsync() override;

	private:

		std::shared_ptr<wmi::IWmiDataContext> m_context;
		std::shared_ptr<ILogger> m_logger;
	};
}