#include <pch.h>


#include "Utilities.h"

winrt::Windows::Foundation::IAsyncAction mta_context(std::function<void()> const& action)
{
    co_await winrt::resume_background();

    action();

    co_return;
}

std::shared_ptr<winrt::AIDA64::Framework::WmiDataContext> get_mta_wmi_context()
{
    static auto context = std::async(std::launch::async, [] {
       return std::make_shared<winrt::AIDA64::Framework::WmiDataContext>();
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

    if (try_get_property(L"Name", object, var) && is_string(var.vt)) {
        model.Name(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"ProcessId", object, var) && is_integer(var.vt)) {
        model.Id(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"ThreadCount", object, var) && is_integer(var.vt)) {
        model.ThreadCount(var.uintVal);
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
   
    if (try_get_property(L"Caption", object, var) && is_string(var.vt)) {
        model.Caption(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"Name", object, var) && is_string(var.vt)) {
        model.Name(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"Manufacturer", object, var) && is_string(var.vt)) {
        model.Manufacturer(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"ProcessorId", object, var) && is_string(var.vt)) {
        model.ProcessorId(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"DeviceId", object, var) && is_string(var.vt)) {
        model.DeviceId(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"PNPDeviceId", object, var) && is_string(var.vt)) {
        model.PNPDeviceId(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"SystemName", object, var) && is_string(var.vt)) {
        model.SystemName(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"CreationClassName", object, var) && is_string(var.vt)) {
        model.CreationClassName(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"Description", object, var) && is_string(var.vt)) {
        model.Description(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"PartNumber", object, var) && is_string(var.vt)) {
        model.PartNumber(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"OtherFamilyDescription", object, var) && is_string(var.vt)) {
        model.OtherFamilyDescription(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"UniqueId", object, var) && is_string(var.vt)) {
        model.UniqueId(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"InstallDate", object, var) && is_string(var.vt)) {
        model.InstallDate(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"Status", object, var) && is_string(var.vt)) {
        model.Status(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"Role", object, var) && is_string(var.vt)) {
        model.Role(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"AddressWidth", object, var) && is_integer(var.vt)) {
        model.AddressWidth(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"DataWidth", object, var) && is_integer(var.vt)) {
        model.DataWidth(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"ExternalClock", object, var) && is_integer(var.vt)) {
        model.ExternalClock(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"CurrentClockSpeed", object, var) && is_integer(var.vt)) {
        model.CurrentClockSpeed(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"MaxClockSpeed", object, var) && is_integer(var.vt)) {
        model.MaxClockSpeed(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"NumberOfCores", object, var) && is_integer(var.vt)) {
        model.NumberOfCores(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"NumberOfLogicalProcessors", object, var) && is_integer(var.vt)) {
        model.NumberOfLogicalProcessors(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"L2CacheSize", object, var) && is_integer(var.vt)) {
        model.L2CacheSize(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"L3CacheSize", object, var) && is_integer(var.vt)) {
        model.L3CacheSize(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"Level", object, var) && is_integer(var.vt)) {
        model.Level(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"LastErrorCode", object, var) && is_integer(var.vt)) {
        model.LastErrorCode(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"LoadPercentage", object, var) && is_integer(var.vt)) {
        model.LoadPercentage(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"Architecture", object, var) && is_integer(var.vt)) {
        model.Architecture(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"Family", object, var) && is_integer(var.vt)) {
        model.Family(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"Stepping", object, var) && is_integer(var.vt)) {
        model.Stepping(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"Revision", object, var) && is_integer(var.vt)) {
        model.Revision(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"CpuStatus", object, var) && is_integer(var.vt)) {
        model.CpuStatus(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"CurrentVoltage", object, var) && is_integer(var.vt)) {
        model.CurrentVoltage(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"StatusInfo", object, var) && is_integer(var.vt)) {
        model.StatusInfo(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"Characteristics", object, var) && is_integer(var.vt)) {
        model.Characteristics(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"UpgradeMethod", object, var) && is_integer(var.vt)) {
        model.UpgradeMethod(var.uintVal);
        var.Clear();
    }
    if (try_get_property(L"PowerManagementSupported", object, var) && is_boolean(var.vt)) {
        model.PowerManagementSupported(var.boolVal);
        var.Clear();
    }
    if (try_get_property(L"ErrorCleared", object, var) && is_boolean(var.vt)) {
        model.ErrorCleared(var.boolVal);
        var.Clear();
    }
    return model;
}

template<>
winrt::AIDA64::DisplayModel from_wbem<winrt::AIDA64::DisplayModel>(winrt::com_ptr<IWbemClassObject> const& object)
{
    winrt::AIDA64::DisplayModel model{};
    _variant_t var;
    VariantInit(&var);

    if (try_get_property(L"Name", object, var) && is_string(var.vt)) {
        model.Name(var.bstrVal);
        var.Clear();
    }
    if (try_get_property(L"DeviceId", object, var) && is_string(var.vt)) {
        model.DeviceId(var.bstrVal);
        var.Clear();
    }
    DEVMODE dev{};
    dev.dmSize = sizeof(DEVMODE);

    if (EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dev))
    {
        model.ScreenHeight(dev.dmPelsHeight);
        model.ScreenWidth(dev.dmPelsWidth);
    }

    return model;
}