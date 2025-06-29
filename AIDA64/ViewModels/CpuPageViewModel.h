#pragma once

#include "CpuPageViewModel.g.h"

#include <Framework/ICpuService.h>
#include <Framework/ILogger.h>

#include <Helpers/BindableBase.h>
#include <Helpers/RelayCommand.h>

namespace winrt
{
    using namespace AIDA64;
    using namespace AIDA64::Framework;
    using namespace AIDA64::Helpers;
}

namespace winrt::AIDA64::implementation
{
    struct CpuPageViewModel : CpuPageViewModelT<CpuPageViewModel, BindableBase>
    {
        CpuPageViewModel();

        void Inject(std::shared_ptr<ICpuService> service, std::shared_ptr<ILogger> logger);

        winrt::CpuModel CpuModel() const noexcept;
        void CpuModel(winrt::CpuModel const& value);

        winrt::IObservableVector<double> Values() const noexcept;
        void Values(winrt::IObservableVector<double> const& value);

    private:

        void Setup();

    private:

        winrt::ICommand TEST;

        winrt::IObservableVector<double> m_values = single_threaded_observable_vector<double>();
        winrt::Windows::System::Threading::ThreadPoolTimer m_timer{ nullptr };

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
