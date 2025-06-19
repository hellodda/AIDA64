#pragma once

#include "MainWindow.g.h"

#include <ViewModels/MainViewModel.h>

#include <Framework/ILogger.h>

namespace winrt
{
    using namespace winrt::AIDA64::Framework;
    using namespace winrt::Windows::Foundation;
    using namespace AIDA64;
}

namespace winrt::AIDA64::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow()
        {
            InitializeComponent();
            Setup();
        }

        void Inject(winrt::MainViewModel const& model, std::shared_ptr<ILogger> logger);
        
        winrt::MainViewModel MainViewModel();

    private:

        void Setup();

    private:

        std::shared_ptr<ILogger> m_logger;

        winrt::MainViewModel m_viewModel;
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
