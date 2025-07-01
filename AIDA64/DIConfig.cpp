#include "pch.h"
#include "DIConfig.h"

std::vector<page_data_t> initialize_pages()
{
    std::vector<page_data_t> pages;

    pages.push_back(page_data_t(
        L"cpu",
        create_model<AIDA64::CpuPageViewModel>(),
        create_view<AIDA64::CpuPage>()
    ));
    pages.push_back(page_data_t(
        L"display",
        create_model<AIDA64::DisplayPageViewModel>(),
        create_view<AIDA64::DisplayPage>()
    ));

    return pages;
}


//---------------------------------------------------------------------------
// models factory \/
//---------------------------------------------------------------------------


template<>
AIDA64::CpuPageViewModel create_model<AIDA64::CpuPageViewModel>()
{
    auto logger = std::make_shared<Logger>();
    auto model = winrt::make<implementation::CpuPageViewModel>();
    auto service = std::make_shared<CpuService>(get_mta_wmi_context(), logger);

    model.as<implementation::CpuPageViewModel>()->Inject(service, logger);

    return model;
}

template<>
AIDA64::MainViewModel create_model<AIDA64::MainViewModel>()
{
    auto logger = std::make_shared<Logger>();
    auto main_view_model = winrt::make<implementation::MainViewModel>();
    main_view_model.as<implementation::MainViewModel>()->Inject(logger);
    return main_view_model;
}

template<>
AIDA64::DisplayPageViewModel create_model<AIDA64::DisplayPageViewModel>()
{
    auto logger = std::make_shared<Logger>();
    auto model = winrt::make<implementation::DisplayPageViewModel>();
    auto service = std::make_shared<DisplayService>(get_mta_wmi_context());
    model.as<implementation::DisplayPageViewModel>()->Inject(service, logger);
    return model;
}

//---------------------------------------------------------------------------
// views factory \/
//---------------------------------------------------------------------------


template<>
AIDA64::MainWindow create_view<AIDA64::MainWindow>()
{
    auto logger = std::make_shared<Logger>();
    auto main_window = winrt::make<implementation::MainWindow>();
    auto model = create_model<AIDA64::MainViewModel>();
    auto pages = initialize_pages();

    main_window.as<implementation::MainWindow>()->Inject(model, logger, pages);

    return main_window;
}


template<>
AIDA64::CpuPage create_view<AIDA64::CpuPage>()
{
    auto cpu_page = winrt::make<implementation::CpuPage>();

    return cpu_page;
}

template<>
AIDA64::DisplayPage create_view<AIDA64::DisplayPage>()
{
    auto page = winrt::make<implementation::DisplayPage>();
    return page;
}