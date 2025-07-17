#include "pch.h"
#include "CpuService.h"

#include <Wmi/WmiMapping.h>
#include "Utilities.h"

namespace winrt::AIDA64::Framework
{
    CpuService::CpuService(std::shared_ptr<wmi::IWmiDataContext> context, std::shared_ptr<ILogger> logger)
        : m_context(std::move(context)), m_logger(std::move(logger)) {
    }

    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<AIDA64::CpuModel>> CpuService::GetCpuInformationAsync()
    {
        if (!m_context || !m_logger)
        {
            throw hresult_error(E_POINTER, L"CpuService: context or logger is null.");
        }

        co_await winrt::resume_background();

        m_logger->log_info("[CpuService] Starting GetCpuInformationAsync...");

        try
        {
            auto result = co_await m_context->QueryAsync(wmi::variables::QUERY_WIN32_PROCESSOR);
            m_logger->log_info("[CpuService] WMI query completed. Processing results...");

            auto models = winrt::single_threaded_vector<AIDA64::CpuModel>();

            for (auto const& wmo : result)
            {
                auto model = wmi::from_wmi<AIDA64::CpuModel>(wmo);
                models.Append(model);

                m_logger->log_info("[CpuService] Detected CPU LoadPercentage = " + std::to_string(model.LoadPercentage()) + "%");
            }

            m_logger->log_info("[CpuService] Successfully retrieved " + std::to_string(models.Size()) + " CPU model(s).");
            co_return models;
        }
        catch (const std::exception& ex)
        {
            m_logger->log_error(std::string("[CpuService] Exception occurred: ") + ex.what());
            throw;
        }
        catch (...)
        {
            m_logger->log_critical("[CpuService] Unknown error occurred.");
            throw;
        }
    }
}
