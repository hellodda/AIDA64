//#pragma once
//
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

namespace di = boost::di;

using namespace winrt::AIDA64::Framework;
using namespace winrt::AIDA64;
using namespace winrt;


inline auto create_injector()
{
  return di::make_injector(
        di::bind<ILogger>().to<Logger>(),

        di::bind<WmiDataContext>().to([&](auto&) -> std::shared_ptr<WmiDataContext> {
            return get_mta_wmi_context();
        }).in(di::singleton),

        di::bind<ICpuService>().to([&](auto& inj) -> std::shared_ptr<ICpuService> {
            auto logger = inj.template create<std::shared_ptr<ILogger>>();
            auto wmi_context = inj.template create<std::shared_ptr<WmiDataContext>>();

            return std::make_shared<CpuService>(wmi_context, logger);
        }).in(di::singleton),

        di::bind<IProcessService>().to([&](auto& inj) -> std::shared_ptr<IProcessService> {
            auto logger = inj.template create<std::shared_ptr<ILogger>>();
            auto wmi_context = inj.template create<std::shared_ptr<WmiDataContext>>();

            return std::make_shared<ProcessService>(wmi_context, logger);
        })
    );
}


//---------------------------------------------------------------------------
// using \/
//---------------------------------------------------------------------------

using InjectorT = decltype(create_injector());


//---------------------------------------------------------------------------
// Primary templates \/
//---------------------------------------------------------------------------

template<typename ModelT>
ModelT create_model(InjectorT const& injector);

template<typename viewT>
viewT create_view(InjectorT const& injector);

//
// >>>sub
//

inline std::vector<page_data_t> initialize_pages(InjectorT const& injector);

//---------------------------------------------------------------------------
// Models Factory \/
//---------------------------------------------------------------------------


template<>
AIDA64::MainViewModel create_model<AIDA64::MainViewModel>(InjectorT const& injector);

template<>
AIDA64::CpuPageViewModel create_model<AIDA64::CpuPageViewModel>(InjectorT const& injector);

template<>
AIDA64::DisplayPageViewModel create_model<AIDA64::DisplayPageViewModel>(InjectorT const& injector);

//---------------------------------------------------------------------------
// Windows Factory \/
//---------------------------------------------------------------------------

template<>
AIDA64::MainWindow create_view<AIDA64::MainWindow>(InjectorT const& injector);

//---------------------------------------------------------------------------
// Pages Factory \/
//---------------------------------------------------------------------------

template<>
AIDA64::CpuPage create_view<AIDA64::CpuPage>(InjectorT const& injector);

template<>
AIDA64::DisplayPage create_view<AIDA64::DisplayPage>(InjectorT const& injector);


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
            auto injector = create_injector();

            auto view = create_view<AIDA64::MainWindow>(injector);

            return view;
        }
    };
}