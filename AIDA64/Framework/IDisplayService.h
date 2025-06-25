#pragma once
#include <Models/DisplayModel.h>

namespace winrt
{
	using namespace Windows::Foundation;
	using namespace AIDA64;
}


namespace winrt::AIDA64::Framework
{
	struct IDisplayService
	{
		virtual IAsyncOperation<DisplayModel> GetDisplayInformationAsync() = 0;
	};
}