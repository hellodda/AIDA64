#pragma once
#include <async/task.h>
#include "WmiObject.h"

namespace winrt
{
	using namespace winrt::Windows::Foundation;
	using namespace winrt::Windows::Foundation::Collections;
}


namespace winrt::AIDA64::Framework
{
	struct IDataContext
	{
		virtual std::vector<wmi::WmiObject> Query(hstring const& query) = 0;
		virtual async::task<std::vector<wmi::WmiObject>> QueryAsync(hstring const& query) = 0;
	};
}