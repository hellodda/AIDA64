#pragma once
#include <Models/ProcessModel.h>
#include <WMIDataContext.h>

namespace winrt::AIDA64::Framework
{
	struct IProcessService
	{
		virtual IAsyncOperation<IVector<ProcessModel>> GetAllProcessesAsync() = 0;
	};
}