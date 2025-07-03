#include <pch.h>
#include <Wmi/WmiDataContext.h>

#include "Utilities.h"

winrt::Windows::Foundation::IAsyncAction mta_context(std::function<void()> const& action)
{
    co_await winrt::resume_background();

    action();

    co_return;
}

std::shared_ptr<wmi::IWmiDataContext> get_mta_wmi_context()
{
    static auto context = std::async(std::launch::async, [] {
       return std::make_shared<wmi::WmiDataContext>();
    }).get();
    return context;
}

void wait(std::function<winrt::Windows::Foundation::IAsyncAction()> action)
{
    std::async(std::launch::async, [&action] {
        action().get();
    }).get();
}

//-------------------------------------------------------------
// other helpers /\ apartment helpers \/
//-------------------------------------------------------------

namespace this_thread
{
    APTTYPE get_apartment_type()
    {
        APTTYPE apt_type;
        APTTYPEQUALIFIER apt_qualifier;

        if (SUCCEEDED(CoGetApartmentType(&apt_type, &apt_qualifier)))
        {
            return apt_type;
        }
        return APTTYPE_NA;
    }

    bool is_mta()
    {
        return get_apartment_type() == APTTYPE_MTA;
    }
    bool is_sta()
    {
        return get_apartment_type() == APTTYPE_STA;
    }
}
