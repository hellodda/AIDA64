#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <unknwnbase.h>
#include <restrictederrorinfo.h>

#include <comutil.h>
#pragma comment(lib, "comsuppw.lib")

#include <WbemIdl.h>
#pragma comment(lib, "wbemuuid.lib")

#undef GetCurrentTime

#include <winrt/base.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.System.Threading.h>
#include <winrt/Windows.ApplicationModel.Activation.h>
#include <winrt/Windows.System.h>

#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <winrt/Microsoft.UI.Xaml.Controls.Primitives.h>
#include <winrt/Microsoft.UI.Xaml.Input.h>
#include <winrt/Microsoft.UI.Xaml.Media.h>
#include <winrt/Microsoft.UI.Xaml.Navigation.h>
#include <winrt/Microsoft.UI.Dispatching.h>


#include <future>
#include <boost/di.hpp>


//
// \/ patom udalyu
//

#define OPEN_CONSOLE                                \
    AllocConsole();                                \
    FILE* stream;                                  \
    freopen_s(&stream, "CONOUT$", "w", stdout);    \
    freopen_s(&stream, "CONOUT$", "w", stderr);    \
    freopen_s(&stream, "CONIN$", "r", stdin);
