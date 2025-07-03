#pragma once
#include <async/task.h>
#include "WmiObject.h"

namespace wmi
{
	struct IWmiDataContext
	{
		virtual std::vector<wmi::WmiObject> Query(_bstr_t const& query) = 0;
		virtual async::task<std::vector<wmi::WmiObject>> QueryAsync(_bstr_t const& query) = 0;
	};
}