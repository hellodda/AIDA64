#pragma once
#include <Models/ProcessorModel.h>
#include <WMIDataContext.h>

namespace winrt
{
	using namespace Windows::Foundation;
	using namespace AIDA64;
}

namespace winrt::AIDA64::Framework
{
	struct ICpuService
	{
		virtual IAsyncOperation<IVector<ProcessorModel>> GetAllProcessorsAsync() = 0;
	};
}