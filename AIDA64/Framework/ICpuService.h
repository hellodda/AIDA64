#pragma once
#include <Models/CpuModel.h>
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
		virtual IAsyncOperation<IVector<CpuModel>> GetAllCpusAsync() = 0;
	};
}