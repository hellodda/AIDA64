#include "pch.h"
#include "App.xaml.h"
#include "MainWindow.xaml.h"
#include "CpuPage.xaml.h"
#include <Win32Helpers/BatteryController.h>

#if __has_include("module.g.cpp")
#  include "module.g.cpp"
#endif

#include "DIConfig.h"

namespace winrt
{
    using namespace Microsoft::UI::Xaml;
    using namespace AIDA64::Framework;
    using namespace AIDA64;
}

namespace winrt::AIDA64::implementation
{
    App::App()
    {

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION
        UnhandledException([](IInspectable const&, UnhandledExceptionEventArgs const& e)
        {
            if (IsDebuggerPresent())
            {
                auto errorMessage = e.Message();
                __debugbreak();
            }
        });
#endif
    }
    void App::OnLaunched([[maybe_unused]] LaunchActivatedEventArgs const& e)
    {
        //OPEN_CONSOLE

        m_factory = std::make_shared<AIDA64::ApplicationFactory>();
    
        m_window = m_factory->create_application_window();

        configuration::ApplicationState::Instance().Window(m_window);
        configuration::ApplicationState::Instance().ConfigureApplication();

        m_window.Activate();
    }
}

