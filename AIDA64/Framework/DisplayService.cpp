#include "pch.h"
#include "DisplayService.h"
#include "Utilities.h"

inline constexpr const wchar_t* QUERY_DISPLAY_LIST = L"SELECT * FROM Win32_DesktopMonitor";

namespace winrt::AIDA64::Framework
{
    DisplayService::DisplayService(std::shared_ptr<IDataContext> context) : m_context(std::move(context))
    {
    }

    IAsyncOperation<DisplayModel> DisplayService::GetDisplayInformationAsync()
    {
        std::vector<com_ptr<IWbemClassObject>> result;

        co_await m_context->QueryAsync(QUERY_DISPLAY_LIST);

        DisplayModel displayModel{};

        for (auto& model : result)
        {
            displayModel = from_wbem<DisplayModel>(model);
        }
        co_return displayModel;
    }
}
