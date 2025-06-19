#pragma once

#include "App.xaml.g.h"

namespace winrt::AIDA64::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);
        void ConfigureDependencies();

    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };
    };
}
