#include "pch.h"
#include "WmiMapping.h"
#include "WmiObject.h"
#include <Models/CpuModel.h>
#include <Models/DisplayModel.h>
#include <Models/ProcessModel.h>
#include <winrt/AIDA64.h>

namespace wmi
{
    template<>
    winrt::AIDA64::CpuModel from_wmi<winrt::AIDA64::CpuModel>(IWmiObject const& object)
    {
        winrt::AIDA64::CpuModel model{};

        if (auto val = object.get_property<std::wstring>(L"Caption"))
            model.Caption(*val);
        if (auto val = object.get_property<std::wstring>(L"Name"))
            model.Name(*val);
        if (auto val = object.get_property<std::wstring>(L"Manufacturer"))
            model.Manufacturer(*val);
        if (auto val = object.get_property<std::wstring>(L"ProcessorId"))
            model.ProcessorId(*val);
        if (auto val = object.get_property<std::wstring>(L"DeviceId"))
            model.DeviceId(*val);
        if (auto val = object.get_property<std::wstring>(L"PNPDeviceId"))
            model.PNPDeviceId(*val);
        if (auto val = object.get_property<std::wstring>(L"SystemName"))
            model.SystemName(*val);
        if (auto val = object.get_property<std::wstring>(L"CreationClassName"))
            model.CreationClassName(*val);
        if (auto val = object.get_property<std::wstring>(L"Description"))
            model.Description(*val);
        if (auto val = object.get_property<std::wstring>(L"PartNumber"))
            model.PartNumber(*val);
        if (auto val = object.get_property<std::wstring>(L"OtherFamilyDescription"))
            model.OtherFamilyDescription(*val);
        if (auto val = object.get_property<std::wstring>(L"UniqueId"))
            model.UniqueId(*val);
        if (auto val = object.get_property<std::wstring>(L"InstallDate"))
            model.InstallDate(*val);
        if (auto val = object.get_property<std::wstring>(L"Status"))
            model.Status(*val);
        if (auto val = object.get_property<std::wstring>(L"Role"))
            model.Role(*val);

        if (auto val = object.get_property<int32_t>(L"AddressWidth"))
            model.AddressWidth(*val);
        if (auto val = object.get_property<int32_t>(L"DataWidth"))
            model.DataWidth(*val);
        if (auto val = object.get_property<int32_t>(L"ExternalClock"))
            model.ExternalClock(*val);
        if (auto val = object.get_property<int32_t>(L"CurrentClockSpeed"))
            model.CurrentClockSpeed(*val);
        if (auto val = object.get_property<int32_t>(L"MaxClockSpeed"))
            model.MaxClockSpeed(*val);
        if (auto val = object.get_property<int32_t>(L"NumberOfCores"))
            model.NumberOfCores(*val);
        if (auto val = object.get_property<int32_t>(L"NumberOfLogicalProcessors"))
            model.NumberOfLogicalProcessors(*val);
        if (auto val = object.get_property<int32_t>(L"L2CacheSize"))
            model.L2CacheSize(*val);
        if (auto val = object.get_property<int32_t>(L"L3CacheSize"))
            model.L3CacheSize(*val);
        if (auto val = object.get_property<int32_t>(L"Level"))
            model.Level(*val);
        if (auto val = object.get_property<int32_t>(L"LastErrorCode"))
            model.LastErrorCode(*val);
        if (auto val = object.get_property<int32_t>(L"LoadPercentage"))
            model.LoadPercentage(*val);
        if (auto val = object.get_property<int32_t>(L"Architecture"))
            model.Architecture(*val);
        if (auto val = object.get_property<int32_t>(L"Family"))
            model.Family(*val);
        if (auto val = object.get_property<int32_t>(L"Stepping"))
            model.Stepping(*val);
        if (auto val = object.get_property<int32_t>(L"Revision"))
            model.Revision(*val);
        if (auto val = object.get_property<int32_t>(L"CpuStatus"))
            model.CpuStatus(*val);
        if (auto val = object.get_property<int32_t>(L"CurrentVoltage"))
            model.CurrentVoltage(*val);
        if (auto val = object.get_property<int32_t>(L"StatusInfo"))
            model.StatusInfo(*val);
        if (auto val = object.get_property<int32_t>(L"Characteristics"))
            model.Characteristics(*val);
        if (auto val = object.get_property<int32_t>(L"UpgradeMethod"))
            model.UpgradeMethod(*val);

        if (auto val = object.get_property<bool>(L"PowerManagementSupported"))
            model.PowerManagementSupported(*val);
        if (auto val = object.get_property<bool>(L"ErrorCleared"))
            model.ErrorCleared(*val);

        return model;
    }

    template<>
    winrt::AIDA64::DisplayModel from_wmi<winrt::AIDA64::DisplayModel>(IWmiObject const& object)
    {
        winrt::AIDA64::DisplayModel model;

        if (auto val = object.get_property<std::wstring>(L"Name"))
            model.Name(*val);
        if (auto val = object.get_property<std::wstring>(L"Caption"))
            model.Caption(*val);
        if (auto val = object.get_property<std::wstring>(L"Description"))
            model.Description(*val);
        if (auto val = object.get_property<std::wstring>(L"DeviceID"))
            model.DeviceId(*val);
        if (auto val = object.get_property<std::wstring>(L"PNPDeviceID"))
            model.PnpDeviceId(*val);
        if (auto val = object.get_property<std::wstring>(L"SystemName"))
            model.SystemName(*val);
        if (auto val = object.get_property<std::wstring>(L"SystemCreationClassName"))
            model.SystemCreationClassName(*val);
        if (auto val = object.get_property<std::wstring>(L"CreationClassName"))
            model.CreationClassName(*val);
        if (auto val = object.get_property<std::wstring>(L"MonitorManufacturer"))
            model.MonitorManufacturer(*val);
        if (auto val = object.get_property<std::wstring>(L"MonitorType"))
            model.MonitorType(*val);
        if (auto val = object.get_property<int32_t>(L"ScreenWidth"))
            model.ScreenWidth(*val);
        if (auto val = object.get_property<int32_t>(L"ScreenHeight"))
            model.ScreenHeight(*val);
        if (auto val = object.get_property<std::wstring>(L"InstanceName"))
            model.InstanceName(*val);
        if (auto val = object.get_property<bool>(L"Active"))
            model.Active(*val);
        if (auto val = object.get_property<int32_t>(L"MaxHorizontalImageSize"))
            model.MaxHorizontalImageSize(*val);
        if (auto val = object.get_property<int32_t>(L"MaxVerticalImageSize"))
            model.MaxVerticalImageSize(*val);
        if (auto val = object.get_property<int32_t>(L"MinRefreshRate"))
            model.MinRefreshRate(*val);
        if (auto val = object.get_property<int32_t>(L"MaxRefreshRate"))
            model.MaxRefreshRate(*val);
        if (auto val = object.get_property<int32_t>(L"Availability"))
            model.Availability(*val);
        if (auto val = object.get_property<bool>(L"PowerManagementSupported"))
            model.PowerManagementSupported(*val);
        if (auto val = object.get_property<bool>(L"ErrorCleared"))
            model.ErrorCleared(*val);
        if (auto val = object.get_property<std::wstring>(L"ErrorDescription"))
            model.ErrorDescription(*val);
        if (auto val = object.get_property<int32_t>(L"ConfigManagerErrorCode"))
            model.ConfigManagerErrorCode(*val);
        if (auto val = object.get_property<bool>(L"ConfigManagerUserConfig"))
            model.ConfigManagerUserConfig(*val);
        if (auto val = object.get_property<std::wstring>(L"InstallDate"))
            model.InstallDate(*val);
        if (auto val = object.get_property<int32_t>(L"LastErrorCode"))
            model.LastErrorCode(*val);
        if (auto val = object.get_property<std::wstring>(L"Status"))
            model.Status(*val);
        if (auto val = object.get_property<int32_t>(L"StatusInfo"))
            model.StatusInfo(*val);
        if (auto val = object.get_property<std::wstring>(L"VideoInputType"))
            model.VideoInputType(*val);

        return model;
    }

}
