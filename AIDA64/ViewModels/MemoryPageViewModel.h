#pragma once

#include "MemoryPageViewModel.g.h"


#include <Helpers/ViewModelBase.h>

#include <Framework/IMemoryService.h>
#include <Framework/ILogger.h>

namespace winrt
{
    using namespace AIDA64;
    using namespace AIDA64::Framework;
    using namespace AIDA64::Helpers;
}

namespace winrt::AIDA64::implementation
{
    struct MemoryPageViewModel : MemoryPageViewModelT<MemoryPageViewModel, ViewModelBase>
    {
        MemoryPageViewModel() = default;

        void Inject(std::shared_ptr<IMemoryService> service, std::shared_ptr<ILogger> logger);

        AIDA64::MemoryModel MemoryModel() const noexcept;
        void MemoryModel(AIDA64::MemoryModel const& model);

        void OnActivate() override;

    private:

        winrt::IAsyncAction LoadDataAsync();

    private:
        AIDA64::MemoryModel m_memory_model{};
        std::shared_ptr<IMemoryService> m_service;
        std::shared_ptr<ILogger> m_logger;
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct MemoryPageViewModel : MemoryPageViewModelT<MemoryPageViewModel, implementation::MemoryPageViewModel>
    {
    };
}
