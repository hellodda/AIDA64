#pragma once
#include <Models/MemoryModel.h>

namespace winrt::AIDA64::Framework
{
	struct IMemoryService
	{
		virtual winrt::Windows::Foundation::IAsyncOperation<AIDA64::MemoryModel> GetMemoryInformationAsync() = 0;
	};
}