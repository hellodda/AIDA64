#pragma once
#include <winrt/Windows.Foundation.h>

namespace winrt::AIDA64::Framework
{
	struct IAiClient
	{
		virtual Windows::Foundation::IAsyncOperation<hstring> SendRequestAsync(hstring const& request) = 0;
	};
}