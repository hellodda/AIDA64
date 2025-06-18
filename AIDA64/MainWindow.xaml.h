#pragma once

#include "MainWindow.g.h"
#include <Framework/ProcessService.h>

namespace winrt::AIDA64::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow()
        {
            InitializeComponent();
        }

    private:

    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
