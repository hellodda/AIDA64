#include "pch.h"
#include "DIConfig.h"

std::vector<page_data_t> initialize_pages(InjectorT const& injector)
{
    std::vector<page_data_t> pages;

    pages.push_back(page_data_t(
        L"cpu",
        create_model<AIDA64::CpuPageViewModel>(injector),
        create_view<AIDA64::CpuPage>(injector))
    );

    return pages;
}


//---------------------------------------------------------------------------
// models factory \/
//---------------------------------------------------------------------------


template<>
AIDA64::CpuPageViewModel create_model<AIDA64::CpuPageViewModel>(InjectorT const& injector)
{
    auto logger = injector.create<std::shared_ptr<ILogger>>();
    auto model = winrt::make<implementation::CpuPageViewModel>();
    auto service = std::make_shared<CpuService>(get_mta_wmi_context(), logger);

    model.as<implementation::CpuPageViewModel>()->Inject(service, logger);

    return model;
}

template<>
AIDA64::MainViewModel create_model<AIDA64::MainViewModel>(InjectorT const& injector)
{
    auto logger = injector.create<std::shared_ptr<ILogger>>();
    auto main_view_model = winrt::make<implementation::MainViewModel>();
    main_view_model.as<implementation::MainViewModel>()->Inject(logger);
    return main_view_model;
}

//---------------------------------------------------------------------------
// views factory \/
//---------------------------------------------------------------------------


template<>
AIDA64::MainWindow create_view<AIDA64::MainWindow>(InjectorT const& injector)
{
    auto logger = injector.create<std::shared_ptr<ILogger>>();
    auto main_window = winrt::make<implementation::MainWindow>();
    auto model = create_model<AIDA64::MainViewModel>(injector);
    auto pages = initialize_pages(injector);

    main_window.as<implementation::MainWindow>()->Inject(model, logger, pages);

    return main_window;
}


template<>
AIDA64::CpuPage create_view<AIDA64::CpuPage>(InjectorT const& injector)
{
    auto cpu_page = winrt::make<implementation::CpuPage>();

    return cpu_page;
}
