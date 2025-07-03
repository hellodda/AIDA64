#pragma once


// \/-- pages - windows--\/ \\

#include "MainWindow.xaml.h"
#include "CpuPage.xaml.h"
#include "DisplayPage.xaml.h"

// \/-- framework --\/ \\

#include <Framework/Logger.h>
#include <Framework/CpuService.h>
#include <Framework/DisplayService.h>
#include <Framework/ProcessService.h>
#include <ViewModels/MainViewModel.h>
#include <ViewModels/DisplayPageViewModel.h>
#include <Wmi/IWmiDataContext.h>

#include <winrt/Windows.Foundation.Collections.h>

using namespace winrt::AIDA64::Framework;
using namespace winrt::AIDA64;
using namespace winrt;



void register_pages();
std::vector<page_data_t> initialize_pages();


template<typename viewT>
viewT create_view();

template<>
AIDA64::MainWindow create_view<AIDA64::MainWindow>();

namespace winrt::AIDA64
{
    struct IApplicationFactory {
        virtual AIDA64::MainWindow create_application_window() = 0;
        virtual ~IApplicationFactory() = default;
    };

    struct ApplicationFactory : IApplicationFactory
    {
        AIDA64::MainWindow create_application_window() override
        {
            auto view = create_view<AIDA64::MainWindow>();

            return view;
        }
    };
}

template<typename T>
struct ServiceFactory
{
    std::shared_ptr<ILogger> m_logger;
    std::shared_ptr<IWmiDataContext> m_context;

    ServiceFactory(std::shared_ptr<ILogger> l, std::shared_ptr<IWmiDataContext> ctx)
        : m_logger(std::move(l)), m_context(std::move(ctx)) {}

    auto Create()
    {
        if constexpr (std::is_constructible_v<T, std::shared_ptr<IWmiDataContext>, std::shared_ptr<ILogger>>)
        {
            return std::make_shared<T>(m_context, m_logger);
        }
        else if constexpr (std::is_constructible_v<T, std::shared_ptr<ILogger>,std::shared_ptr<IWmiDataContext>>)
        {
            return std::make_shared<T>(m_logger, m_context);
        }
        else
            return nullptr;
    }
};

template<typename T, typename ST>
struct ViewModelFactory 
{
    std::shared_ptr<ST> m_service;
    std::shared_ptr<ILogger> m_logger;

    ViewModelFactory(std::shared_ptr<ST> s, std::shared_ptr<ILogger> l) : m_service(s), m_logger(l) {}

    auto Create()
    {
        auto model = winrt::make<T>();
        auto self = winrt::get_self<T>(model);

        if constexpr (requires { self->Inject(m_service, m_logger); })
            self->Inject(m_service, m_logger);
        else if constexpr (requires { self->Inject(m_service); })
            self->Inject(m_service);

        return model;
    }
};

template<typename T>
struct ViewFactory
{
    auto Create()
    {
        return winrt::make<T>();
    }
};

struct hstring_less
{
    bool operator()(winrt::hstring const& a, winrt::hstring const& b) const noexcept
    {
        return std::wstring_view{ a } < std::wstring_view{ b };
    }
};


class PageRegistry
{
public:
    static PageRegistry& Instance()
    {
        static PageRegistry instance;
        return instance;
    }

    void RegisterPage(page_data_t page)
    {
        m_pages[page.tag] = std::move(page);
    }

    const auto& Pages() const { return m_pages; }

private:
    std::map<winrt::hstring, page_data_t, hstring_less> m_pages;
};

template<typename InterfaceT, typename ServiceT, typename ViewModelT, typename ViewT>
void register_page_entry(std::wstring_view tag, std::shared_ptr<ILogger> logger, std::shared_ptr<IWmiDataContext> ctx)
{
    auto service = ServiceFactory<ServiceT>(logger, ctx).Create();
    auto vm = ViewModelFactory<ViewModelT, InterfaceT>(service, logger).Create();
    auto view = ViewFactory<ViewT>().Create();
    PageRegistry::Instance().RegisterPage({ winrt::hstring{tag}, vm, view });
}