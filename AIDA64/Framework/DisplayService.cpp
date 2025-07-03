#include "pch.h"
#include "DisplayService.h"

#include <Wmi/WmiMapping.h>

inline constexpr const wchar_t* QUERY_DISPLAY_LIST = L"SELECT * FROM Win32_DesktopMonitor";

namespace winrt::AIDA64::Framework
{
    DisplayService::DisplayService(std::shared_ptr<wmi::IWmiDataContext> context)
        : m_context(std::move(context)) {}

    Windows::Foundation::IAsyncOperation<AIDA64::DisplayModel>DisplayService::GetDisplayInformationAsync()
    {
        co_await winrt::resume_background();

        auto result = co_await m_context->QueryAsync(QUERY_DISPLAY_LIST);

        AIDA64::DisplayModel model{};

        for (auto const& wmo : result)
        {
            model = wmi::from_wmi<DisplayModel>(wmo);
        }
        co_return model;
    }
}