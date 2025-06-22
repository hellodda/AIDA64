#pragma once

#pragma once
#include <Framework/Logger.h>
#include <Framework/ProcessService.h>
#include <ViewModels/MainViewModel.h>

namespace di = boost::di;

namespace winrt
{
    using namespace AIDA64;
    using namespace AIDA64::Framework;
    using namespace Windows::Foundation;
}

using namespace winrt;

inline auto CreateInjector()
{
    return di::make_injector(

        di::bind<ILogger>.to<Logger>().in(di::singleton)

    );
}