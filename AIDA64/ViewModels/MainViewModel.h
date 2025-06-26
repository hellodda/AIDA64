#pragma once

#include "MainViewModel.g.h"

#include <Helpers/BindableBase.h>
#include <Helpers/RelayCommand.h>

#include <Framework/ILogger.h>
#include <Framework/IProcessService.h>

namespace winrt
{
    using namespace Windows::Foundation;
    using namespace Windows::Foundation::Collections;
    using namespace Microsoft::UI::Xaml::Data;
    using namespace AIDA64::Framework;
    using namespace AIDA64::Helpers;
}

namespace winrt::AIDA64::implementation
{
    struct MainViewModel : MainViewModelT<MainViewModel, Helpers::BindableBase>
    {
        MainViewModel();

        void Inject(std::shared_ptr<ILogger> logger);

    private:

        std::shared_ptr<ILogger> m_logger;
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct MainViewModel : MainViewModelT<MainViewModel, implementation::MainViewModel>
    {
    };
}
