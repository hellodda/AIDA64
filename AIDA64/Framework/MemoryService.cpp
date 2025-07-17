#include "pch.h"
#include "MemoryService.h"

#include <Wmi/WmiMapping.h>

namespace winrt::AIDA64::Framework
{
    MemoryService::MemoryService(std::shared_ptr<wmi::IWmiDataContext> context, std::shared_ptr<ILogger> logger)
        : m_context(std::move(context)), m_logger(std::move(logger)) {
    }

    Windows::Foundation::IAsyncOperation<AIDA64::MemoryModel> MemoryService::GetMemoryInformationAsync()
    {
        if (!m_context || !m_logger)
        {
            throw hresult_error(E_POINTER, L"MemoryService: context or logger is null.");
        }

        co_await winrt::resume_background();

        m_logger->log_info("[MemoryService] Starting GetMemoryInformationAsync...");

        try
        {
            auto result = co_await m_context->QueryAsync(wmi::variables::QUERY_WIN32_PHYSICAL_MEMORY);
            m_logger->log_info("[MemoryService] WMI query completed. Parsing results...");

            AIDA64::MemoryModel model{};

            for (auto const& wmo : result)
            {
                model = wmi::from_wmi<AIDA64::MemoryModel>(wmo);
                m_logger->log_info("[MemoryService] Memory module parsed.");
            }

            m_logger->log_info("[MemoryService] Returning memory model.");
            co_return model;
        }
        catch (const std::exception& ex)
        {
            m_logger->log_error(std::string("[MemoryService] Exception occurred: ") + ex.what());
            throw;
        }
        catch (...)
        {
            m_logger->log_critical("[MemoryService] Unknown error occurred.");
            throw;
        }
    }
}
