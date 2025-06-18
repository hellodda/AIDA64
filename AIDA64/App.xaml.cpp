#include "pch.h"
#include "App.xaml.h"
#include "MainWindow.xaml.h"

#if __has_include("module.g.cpp")
#  include "module.g.cpp"
#endif


using namespace winrt;
using namespace Microsoft::UI::Xaml;

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
        OPEN_CONSOLE

        window = make<MainWindow>();
        window.Activate();
    }
}
