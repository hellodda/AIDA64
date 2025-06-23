#pragma once

#include "CpuPageViewModel.g.h"
#include <Framework/ICpuService.h>
#include <Framework/ILogger.h>

#include <Helpers/BindableBase.h>

namespace winrt
{
    using namespace AIDA64;
    using namespace AIDA64::Framework;
}

namespace winrt::AIDA64::implementation
{
    struct CpuPageViewModel : CpuPageViewModelT<CpuPageViewModel, implementation::BindableBase>
    {
        CpuPageViewModel() = default;

        void Inject(std::shared_ptr<ICpuService> service, std::shared_ptr<ILogger> logger);

        winrt::CpuModel CpuModel();
        void CpuModel(winrt::CpuModel const& value);

    private:
        winrt::CpuModel m_cpu_model;

        std::shared_ptr<ICpuService> m_service;
        std::shared_ptr<ILogger> m_logger;
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct CpuPageViewModel : CpuPageViewModelT<CpuPageViewModel, implementation::CpuPageViewModel>
    {
    };
}
