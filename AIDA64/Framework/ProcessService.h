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
		ProcessService(std::shared_ptr<IDataContext> context);

		IAsyncOperation<IVector<ProcessModel>> GetAllProcessesAsync() override;

	private:

		std::shared_ptr<IDataContext> m_context;
	};
}

