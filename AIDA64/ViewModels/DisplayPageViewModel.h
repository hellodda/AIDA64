#pragma once

#include "DisplayPageViewModel.g.h"

#include <Framework/IDisplayService.h>
#include <Framework/ILogger.h>

#include <Helpers/BindableBase.h>
#include <Helpers/RelayCommand.h>
#include <Helpers/ViewModelBase.h>

namespace winrt
{
    using namespace AIDA64;
    using namespace AIDA64::Framework;
    using namespace AIDA64::Helpers;
}

namespace winrt::AIDA64::implementation
{
    struct DisplayPageViewModel : DisplayPageViewModelT<DisplayPageViewModel, ViewModelBase>
    {
        DisplayPageViewModel() = default;

        void Inject(std::shared_ptr<IDisplayService> service, std::shared_ptr<ILogger> logger);

        winrt::DisplayModel DisplayModel();
        void DisplayModel(winrt::DisplayModel const& value);

        void OnActivate() override;

    private:

        IAsyncAction LoadDataAsync();

    private:

        winrt::DisplayModel m_display_model;
       
        std::shared_ptr<IDisplayService> m_service;
        std::shared_ptr<ILogger> m_logger;
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct DisplayPageViewModel : DisplayPageViewModelT<DisplayPageViewModel, implementation::DisplayPageViewModel>
    {
    };
}
