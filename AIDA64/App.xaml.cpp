#include "pch.h"
#include "App.xaml.h"
#include "MainWindow.xaml.h"
#include <Framework/CpuService.h>

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
        OPEN_CONSOLE
       
        ConfigureDependencies();

        window.Activate();
    }

    void AIDA64::implementation::App::ConfigureDependencies()
    {
        auto injector = CreateInjector();

        auto logger = injector.create<std::shared_ptr<ILogger>>();

        auto main_view_model = winrt::make<implementation::MainViewModel>();

        main_view_model.as<implementation::MainViewModel>()->Inject(logger);

        window = make<MainWindow>();

        window.as<MainWindow>()->Inject(main_view_model, logger);
    }
}
