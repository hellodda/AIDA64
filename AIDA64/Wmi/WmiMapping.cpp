#include "pch.h"
#include "WmiMapping.h"
#include "WmiObject.h"
#include <Models/CpuModel.h>
#include <Models/DisplayModel.h>
#include <Models/ProcessModel.h>
#include <winrt/AIDA64.h>

#define MAP_PROPERTY(type, property_name) \
    if (auto val = object.get_property<type>(L#property_name)) model.property_name(*val);

#define MAP_PROPERTY_EX(type, property_name, setter_name) \
    if (auto val = object.get_property<type>(L#property_name)) model.setter_name(*val);

namespace wmi
{
    template<>
    winrt::AIDA64::CpuModel from_wmi<winrt::AIDA64::CpuModel>(IWmiObject const& object)
    {
        winrt::AIDA64::CpuModel model{};

        MAP_PROPERTY(std::wstring, Caption)
        MAP_PROPERTY(std::wstring, Name)
        MAP_PROPERTY(std::wstring, Manufacturer)
        MAP_PROPERTY(std::wstring, ProcessorId)
        MAP_PROPERTY(std::wstring, DeviceId)
        MAP_PROPERTY(std::wstring, PNPDeviceId)
        MAP_PROPERTY(std::wstring, SystemName)
        MAP_PROPERTY(std::wstring, CreationClassName)
        MAP_PROPERTY(std::wstring, Description)
        MAP_PROPERTY(std::wstring, PartNumber)
        MAP_PROPERTY(std::wstring, OtherFamilyDescription)
        MAP_PROPERTY(std::wstring, UniqueId)
        MAP_PROPERTY(std::wstring, InstallDate)
        MAP_PROPERTY(std::wstring, Status)
        MAP_PROPERTY(std::wstring, Role)

        MAP_PROPERTY(int32_t, AddressWidth)
        MAP_PROPERTY(int32_t, DataWidth)
        MAP_PROPERTY(int32_t, ExternalClock)
        MAP_PROPERTY(int32_t, CurrentClockSpeed)
        MAP_PROPERTY(int32_t, MaxClockSpeed)
        MAP_PROPERTY(int32_t, NumberOfCores)
        MAP_PROPERTY(int32_t, NumberOfLogicalProcessors)
        MAP_PROPERTY(int32_t, L2CacheSize)
        MAP_PROPERTY(int32_t, L3CacheSize)
        MAP_PROPERTY(int32_t, Level)
        MAP_PROPERTY(int32_t, LastErrorCode)
        MAP_PROPERTY(int32_t, LoadPercentage)
        MAP_PROPERTY(int32_t, Architecture)
        MAP_PROPERTY(int32_t, Family)
        MAP_PROPERTY(int32_t, Stepping)
        MAP_PROPERTY(int32_t, Revision)
        MAP_PROPERTY(int32_t, CpuStatus)
        MAP_PROPERTY(int32_t, CurrentVoltage)
        MAP_PROPERTY(int32_t, StatusInfo)
        MAP_PROPERTY(int32_t, Characteristics)
        MAP_PROPERTY(int32_t, UpgradeMethod)

        MAP_PROPERTY(bool, PowerManagementSupported)
        MAP_PROPERTY(bool, ErrorCleared)

        return model;
    }

    template<>
    winrt::AIDA64::DisplayModel from_wmi<winrt::AIDA64::DisplayModel>(IWmiObject const& object)
    {
        winrt::AIDA64::DisplayModel model;

        MAP_PROPERTY(std::wstring, Name)
        MAP_PROPERTY(std::wstring, Caption)
        MAP_PROPERTY(std::wstring, Description)
        MAP_PROPERTY(std::wstring, DeviceId)
        MAP_PROPERTY(std::wstring, PnpDeviceId)
        MAP_PROPERTY(std::wstring, SystemName)
        MAP_PROPERTY(std::wstring, SystemCreationClassName)
        MAP_PROPERTY(std::wstring, CreationClassName)
        MAP_PROPERTY(std::wstring, MonitorManufacturer)
        MAP_PROPERTY(std::wstring, MonitorType)
        MAP_PROPERTY(std::wstring, InstanceName)
        MAP_PROPERTY(std::wstring, ErrorDescription)
        MAP_PROPERTY(std::wstring, InstallDate)
        MAP_PROPERTY(std::wstring, Status)
        MAP_PROPERTY(std::wstring, VideoInputType)
      
        MAP_PROPERTY(int32_t, MaxHorizontalImageSize)
        MAP_PROPERTY(int32_t, MaxVerticalImageSize)
        MAP_PROPERTY(int32_t, MinRefreshRate)
        MAP_PROPERTY(int32_t, MaxRefreshRate)
        MAP_PROPERTY(int32_t, Availability)
        MAP_PROPERTY(int32_t, ScreenWidth)
        MAP_PROPERTY(int32_t, ScreenHeight)
        MAP_PROPERTY(int32_t, ConfigManagerErrorCode)
        MAP_PROPERTY(int32_t, LastErrorCode)
        MAP_PROPERTY(int32_t, StatusInfo)

        MAP_PROPERTY(bool, PowerManagementSupported)
        MAP_PROPERTY(bool, ErrorCleared)
        MAP_PROPERTY(bool, ConfigManagerUserConfig)
        MAP_PROPERTY(bool, Active)

        return model;
    }
}

#undef MAP_PROPERTY_EX
#undef MAP_PROPERTY
