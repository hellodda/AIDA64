#include "pch.h"
#include "DIConfig.h"

void register_pages()
{
    auto logger = std::make_shared<Logger>();
    auto context = get_mta_wmi_context(); 

    register_page_entry<ICpuService, CpuService, implementation::CpuPageViewModel, implementation::CpuPage>(L"cpu", logger, context);

    register_page_entry<IDisplayService, DisplayService, implementation::DisplayPageViewModel, implementation::DisplayPage>(L"display", logger, context);

    register_page_entry<IMemoryService, MemoryService, implementation::MemoryPageViewModel, implementation::MemoryPage>(L"mem", logger, context);

    register_page_entry<IAiClient, AiClient, implementation::AiPageViewModel, implementation::AiPage>(L"ai", nullptr, nullptr);
}

std::vector<page_data_t> initialize_pages()
{
    std::vector<page_data_t> pages;
    for (auto& [tag, page] : PageRegistry::Instance().Pages())
    {
        if (tag == L"main") continue;

        pages.emplace_back(page);
    }
    return pages;
}

template<>
AIDA64::MainWindow create_view<AIDA64::MainWindow>()
{
    register_pages();

    auto model = winrt::make<implementation::MainViewModel>();

    auto window = winrt::make<implementation::MainWindow>();

    auto pages = initialize_pages();

    window.as<implementation::MainWindow>()->Inject(model, std::make_shared<Logger>(), pages);

    return window;
}