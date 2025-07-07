#pragma once

#include "App.xaml.g.h"
#include "DIConfig.h"
#include <Config/ApplicationState.h>


namespace winrt::AIDA64::implementation
{
    struct App : AppT<App>
    {
        App();

        Microsoft::UI::Xaml::Window MainWindow() const noexcept { return m_window; }

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

    private:
        winrt::Microsoft::UI::Xaml::Window m_window{ nullptr };
        std::shared_ptr<AIDA64::IApplicationFactory> m_factory{ nullptr };
    };
}
