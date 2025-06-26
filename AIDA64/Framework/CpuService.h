#pragma once
#include "ICpuService.h"
#include "ILogger.h"
#include <Models/CpuModel.h>

namespace winrt
{
	using namespace AIDA64;
	using namespace Windows::Foundation;
}

namespace winrt::AIDA64::Framework
{
	struct CpuService : ICpuService
	{
		CpuService(std::shared_ptr<IDataContext> context, std::shared_ptr<ILogger> logger);

		IAsyncOperation<IVector<CpuModel>> GetCpuInformationAsync() override;

	private:

		std::shared_ptr<IDataContext> m_context;
		std::shared_ptr<ILogger> m_logger;
	};
}