#include <pch.h>


#include "Utilities.h"

IAsyncAction mta_context(std::function<void()> const& action)
{
    co_await winrt::resume_background();

    action();

    co_return;
}

std::shared_ptr<AIDA64::Framework::WmiDataContext> get_mta_wmi_context()
{
    static auto context = std::async(std::launch::async, [] {
       return std::make_shared<AIDA64::Framework::WmiDataContext>();
    }).get();
    return context;
}

void wait(std::function<IAsyncAction()> action)
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

//-------------------------------------------------------------
// \/ helper functions for defining types /\ apartment helpers
//-------------------------------------------------------------

bool is_integer(VARTYPE const& type)
{
    return (type == VT_I4 || type == VT_UI4 || type == VT_INT || type == VT_UINT);
}
bool is_string(VARTYPE const& type)
{
    return type == VT_BSTR;
}
bool is_boolean(VARTYPE const& type)
{
    return type == VT_BOOL;
}
bool try_get_property(std::wstring const& property_name, winrt::com_ptr<IWbemClassObject> const& object,  _variant_t& variant)
{
    return SUCCEEDED(object->Get(property_name.c_str(), NULL, &variant, NULL, NULL));
}

//-------------------------------------------------------------
// \/ parsing /\ helper functions for defining types
//-------------------------------------------------------------

template<>
winrt::AIDA64::ProcessModel from_wbem<winrt::AIDA64::ProcessModel>(winrt::com_ptr<IWbemClassObject> const& object)
{
    winrt::AIDA64::ProcessModel model{};
    _variant_t var;

    VariantInit(&var);

    if (try_get_property(L"Name", object, var)) {
        if (is_string(var.vt)) model.Name(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"ProcessId", object, var)) {
        if (is_integer(var.vt)) model.Id(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"ThreadCount", object, var)) {
        if (is_integer(var.vt)) model.ThreadCount(var.uintVal);
        var.Clear();
    }
    return model;
}

template<>
winrt::AIDA64::CpuModel from_wbem<winrt::AIDA64::CpuModel>(winrt::com_ptr<IWbemClassObject> const& object)
{
    winrt::AIDA64::CpuModel model{};
    _variant_t var;

    VariantInit(&var);

    if (try_get_property(L"Name", object, var)) {
        if (is_string(var.vt)) model.Name(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"Manufacturer", object, var)) {
        if (is_string(var.vt)) model.Manufacturer(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"ProcessorId", object, var)) {
        if (is_string(var.vt)) model.Id(var.bstrVal);
        var.Clear();
    }

    //int \/
    if (try_get_property(L"NumberOfCores", object, var)) {
        if (is_integer(var.vt)) model.CoreCount(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"MaxClockSpeed", object, var)) {
        if (is_integer(var.vt)) model.MaxClockSpeed(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"CurrentClockSpeed", object, var)) {
        if (is_integer(var.vt)) model.CurrentClockSpeed(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"LoadPercentage", object, var)) {
        if (is_integer(var.vt)) model.LoadPercentage(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"Architecture", object, var)) {
        if (is_integer(var.vt)) model.Architecture(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"AddressWidth", object, var)) {
        if (is_integer(var.vt)) model.AddressWidth(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"DataWidth", object, var)) {
        if (is_integer(var.vt)) model.DataWidth(var.uintVal);
        var.Clear();
    }
    return model;
}