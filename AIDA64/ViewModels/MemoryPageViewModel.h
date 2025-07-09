#pragma once

#include "MemoryPageViewModel.g.h"

#include <Helpers/BindableBase.h>
#include <Framework/IMemoryService.h>

namespace winrt
{
    using namespace AIDA64;
    using namespace AIDA64::Framework;
    using namespace AIDA64::Helpers;
}

namespace winrt::AIDA64::implementation
{
    struct MemoryPageViewModel : MemoryPageViewModelT<MemoryPageViewModel, BindableBase>
    {
        MemoryPageViewModel() = default;

        void Inject(std::shared_ptr<IMemoryService> service);

        AIDA64::MemoryModel MemoryModel() const noexcept;
        void MemoryModel(AIDA64::MemoryModel const& model);

        void Activate();

    private:

        winrt::IAsyncAction LoadDataAsync();

    private:

        AIDA64::MemoryModel m_memory_model{};
        std::shared_ptr<IMemoryService> m_service;
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct MemoryPageViewModel : MemoryPageViewModelT<MemoryPageViewModel, implementation::MemoryPageViewModel>
    {
    };
}
