#include "pch.h"
#include "ProcessService.h"

#include <Wmi/WmiMapping.h>

namespace winrt::AIDA64::Framework
{
    ProcessService::ProcessService(std::shared_ptr<wmi::IWmiDataContext> context)
        : m_context(std::move(context)) {}

    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<AIDA64::ProcessModel>>ProcessService::GetAllProcessesAsync()
    {
        co_await winrt::resume_background();

        auto result = co_await m_context->QueryAsync(wmi::variables::QUERY_WIN32_PROCESS);

        auto models = winrt::single_threaded_vector<AIDA64::ProcessModel>();

        for (auto const& wmo : result)
        {
            //auto model = wmi::from_wbem<winrt::AIDA64::ProcessModel>(wbemObject);
            //models.Append(model);
        }

        co_return models;
    }
}