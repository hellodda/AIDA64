#pragma once
#include <Models/ProcessModel.h>
#include <WMIDataContext.h>

namespace winrt
{
	using namespace Windows::Foundation;
}

namespace winrt::AIDA64::Framework
{
	struct ProcessService
	{
		ProcessService(WmiDataContext context);

		IAsyncOperation<IVector<ProcessModel>> GetAllProcessesAsync();

	private:

		WmiDataContext m_context;
	};
}

