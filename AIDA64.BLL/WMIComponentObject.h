#pragma once

#include "WMIComponentObject.g.h"

namespace winrt::AIDA64_BLL::implementation
{
    struct WMIComponentObject : WMIComponentObjectT<WMIComponentObject>
    {
        WMIComponentObject() = default;

    };
}

namespace winrt::AIDA64_BLL::factory_implementation
{
    struct WMIComponentObject : WMIComponentObjectT<WMIComponentObject, implementation::WMIComponentObject>
    {
    };
}
