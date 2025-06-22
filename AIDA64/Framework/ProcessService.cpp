#include "pch.h"
#include "Utilities.h"
#include "ProcessService.h"

inline constexpr const wchar_t* QUERY_PROCESS_LIST = L"SELECT * FROM Win32_Process";
inline constexpr const wchar_t* QUERY_PROCESS_FROM = L"SELECT * FROM Win32_Process WHERE";

namespace winrt::AIDA64::Framework
{
	ProcessService::ProcessService(std::shared_ptr<WmiDataContext> context)
	{
		m_context = std::move(context);
	}

	IAsyncOperation<IVector<ProcessModel>> ProcessService::GetAllProcessesAsync()
	{
		std::vector<com_ptr<IWbemClassObject>> result;

		co_await m_context->QueryAsync(QUERY_PROCESS_LIST, result);

		IVector<ProcessModel> models = single_threaded_vector<ProcessModel>();

		for (auto& object : result)
		{
			auto model = from_wbem<ProcessModel>(object);
			models.Append(model);
		}
		co_return models;
	}
}

