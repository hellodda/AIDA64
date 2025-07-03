#include "pch.h"
#include "DisplayService.h"

#include <Wmi/WmiMapping.h>


namespace winrt::AIDA64::Framework
{
    DisplayService::DisplayService(std::shared_ptr<wmi::IWmiDataContext> context)
        : m_context(std::move(context)) {}

    Windows::Foundation::IAsyncOperation<AIDA64::DisplayModel>DisplayService::GetDisplayInformationAsync()
    {
        co_await winrt::resume_background();

        auto result = co_await m_context->QueryAsync(wmi::variables::QUERY_WIN32_DESKTOP_MONITOR);

        AIDA64::DisplayModel model{};

        for (auto const& wmo : result)
        {
            model = wmi::from_wmi<DisplayModel>(wmo);
        }
        co_return model;
    }
}