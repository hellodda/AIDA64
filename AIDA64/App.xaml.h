#pragma once

#include "App.xaml.g.h"
#include "DIConfig.h"

namespace winrt::AIDA64::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);
        
        void StartTimer();

    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };
        std::shared_ptr<AIDA64::IApplicationFactory> m_factory{ nullptr };
        winrt::Windows::System::Threading::ThreadPoolTimer m_timer{ nullptr };
    };
}
