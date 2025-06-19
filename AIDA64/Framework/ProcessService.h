#pragma once
#include "IProcessService.h"

namespace winrt
{
	using namespace Windows::Foundation;
}

namespace winrt::AIDA64::Framework
{
	struct ProcessService : IProcessService
	{
		ProcessService(WmiDataContext context);

		IAsyncOperation<IVector<ProcessModel>> GetAllProcessesAsync() override;

	private:

		WmiDataContext m_context;
	};
}

