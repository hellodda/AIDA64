#include "pch.h"
#include "Utilities.h"
#include "ProcessService.h"

namespace winrt::AIDA64::Framework
{
	ProcessService::ProcessService(WmiDataContext context)
	{
		m_context = context;
	}

	IAsyncOperation<IVector<ProcessModel>> ProcessService::GetAllProcessesAsync()
	{
		auto result = co_await m_context.QueryAsync(L"SELECT * FROM Win32_Process");

		IVector<ProcessModel> models = single_threaded_vector<ProcessModel>();

		for (auto& object : result)
		{
			auto model = from_wbem<ProcessModel>(object);
			models.Append(model);
		}
		co_return models;
	}
}

