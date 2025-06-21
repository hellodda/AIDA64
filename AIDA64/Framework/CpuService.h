#pragma once
#include "ICpuService.h"
#include "ILogger.h"

namespace winrt
{
	using namespace Windows::Foundation;
}

namespace winrt::AIDA64::Framework
{
	struct CpuService : ICpuService
	{
		CpuService(std::shared_ptr<WmiDataContext> context, std::shared_ptr<ILogger> logger);

		IAsyncOperation<IVector<CpuModel>> GetAllProcessorsAsync() override;

	private:

		std::shared_ptr<WmiDataContext> m_context;
		std::shared_ptr<ILogger> m_logger;
	};
}