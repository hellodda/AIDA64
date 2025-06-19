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
    struct MainViewModel : MainViewModelT<MainViewModel, BindableBase>
    {
        MainViewModel();

        void Inject(std::shared_ptr<ILogger> logger);

        ICommand NavigateCommand();

        INotifyPropertyChanged SelectedPage();
        void SelectedPage(INotifyPropertyChanged const& value);

    private:

        winrt::IObservableVector<INotifyPropertyChanged> m_pages = single_threaded_observable_vector<INotifyPropertyChanged>();
        winrt::INotifyPropertyChanged m_selectedPage{};
        winrt::ICommand m_navigateCommand;

        std::shared_ptr<ILogger> m_logger;
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct MainViewModel : MainViewModelT<MainViewModel, implementation::MainViewModel>
    {
    };
}
