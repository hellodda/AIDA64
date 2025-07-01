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

using namespace winrt::AIDA64::Framework;
using namespace winrt::AIDA64;
using namespace winrt;

//---------------------------------------------------------------------------
// Primary templates \/
//---------------------------------------------------------------------------

template<typename ModelT>
ModelT create_model();

template<typename viewT>
viewT create_view();

//
// >>>sub
//

inline std::vector<page_data_t> initialize_pages();

//---------------------------------------------------------------------------
// Models Factory \/
//---------------------------------------------------------------------------


template<>
AIDA64::MainViewModel create_model<AIDA64::MainViewModel>();

template<>
AIDA64::CpuPageViewModel create_model<AIDA64::CpuPageViewModel>();

template<>
AIDA64::DisplayPageViewModel create_model<AIDA64::DisplayPageViewModel>();

//---------------------------------------------------------------------------
// Windows Factory \/
//---------------------------------------------------------------------------

template<>
AIDA64::MainWindow create_view<AIDA64::MainWindow>();

//---------------------------------------------------------------------------
// Pages Factory \/
//---------------------------------------------------------------------------

template<>
AIDA64::CpuPage create_view<AIDA64::CpuPage>();

template<>
AIDA64::DisplayPage create_view<AIDA64::DisplayPage>();


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