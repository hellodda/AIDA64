#include "pch.h"
#include "App.xaml.h"
#include "MainWindow.xaml.h"
#include <Framework/CpuService.h>
#include <ViewModels/CpuPageViewModel.h>
#include "CpuPage.xaml.h"

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

        std::shared_ptr<ICpuService> cpu_service = std::make_shared<CpuService>(get_mta_wmi_context(), logger);

        auto main_view_model = winrt::make<implementation::MainViewModel>();

        main_view_model.as<implementation::MainViewModel>()->Inject(logger);

        auto cpu_page_model = winrt::make<implementation::CpuPageViewModel>();

        cpu_page_model.as<implementation::CpuPageViewModel>()->Inject(cpu_service, logger);

        auto cpu_page = winrt::make<implementation::CpuPage>();

        std::vector<page_data_t> pages;
        pages.push_back(page_data_t(L"cpu", cpu_page_model, cpu_page));

        window = make<MainWindow>();

        window.as<MainWindow>()->Inject(main_view_model, logger, pages);
    }
    void App::StartTimer()  
    {  
        using namespace std::chrono_literals; 

        m_timer = winrt::Windows::System::Threading::ThreadPoolTimer::CreatePeriodicTimer([](winrt::Windows::System::Threading::ThreadPoolTimer const& time) {  
            OutputDebugString(L"Таймер сработал!\n");  
        }, 1000ms);  
    }
}
