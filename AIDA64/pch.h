#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <windows.h>
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
#include <winrt/Windows.ApplicationModel.Activation.h>
#include <winrt/Windows.System.h>

#include <winrt/Microsoft.UI.Composition.h>
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <winrt/Microsoft.UI.Xaml.Controls.Primitives.h>
#include <winrt/Microsoft.UI.Xaml.Data.h>
#include <winrt/Microsoft.UI.Xaml.Input.h>
#include <winrt/Microsoft.UI.Xaml.Markup.h>
#include <winrt/Microsoft.UI.Xaml.Media.h>
#include <winrt/Microsoft.UI.Xaml.Navigation.h>
#include <winrt/Microsoft.UI.Xaml.Shapes.h>
#include <winrt/Microsoft.UI.Dispatching.h>

#include <wil/cppwinrt_helpers.h>
#include <future>
#include <functional>

//
// \/ patom udalyu
//

#define OPEN_CONSOLE                                \
    AllocConsole();                                \
    FILE* stream;                                  \
    freopen_s(&stream, "CONOUT$", "w", stdout);    \
    freopen_s(&stream, "CONOUT$", "w", stderr);    \
    freopen_s(&stream, "CONIN$", "r", stdin);
