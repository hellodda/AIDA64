#include <pch.h>
#include "Utilities.h"

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
    return (type == VT_I4 || type == VT_UI4);
}
bool is_string(VARTYPE const& type)
{
    return type == VT_BSTR;
}
bool is_boolean(VARTYPE const& type)
{
    return type == VT_BOOL;
}
bool try_get_property(std::wstring const& property_name, winrt::com_ptr<IWbemClassObject> const& object,  VARIANT& variant)
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
    VARIANT var;

    VariantInit(&var);

    if (try_get_property(L"Name", object, var)) {
        if (is_string(var.vt)) model.Name(var.bstrVal);
        VariantClear(&var);
    }
    if (try_get_property(L"ProcessId", object, var)) {
        if (is_integer(var.vt)) model.Id(var.uintVal);
        VariantClear(&var);
    }
    if (try_get_property(L"ThreadCount", object, var)) {
        if (is_integer(var.vt)) model.ThreadCount(var.uintVal);
        VariantClear(&var);
    }
    return model;
}

