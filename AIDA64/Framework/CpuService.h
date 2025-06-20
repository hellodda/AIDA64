#pragma once
#include "ICpuService.h"

namespace winrt
{
	using namespace Windows::Foundation;
}

namespace winrt::AIDA64::Framework
{
	struct CpuService : ICpuService
	{
		CpuService(std::shared_ptr<WmiDataContext> context);

		IAsyncOperation<IVector<ProcessorModel>> GetAllProcessorsAsync() override;

	private:

		std::shared_ptr<WmiDataContext> m_context;
	};
}