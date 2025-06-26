#pragma once

#include "DisplayModel.g.h"
#include <winrt/Windows.Foundation.Collections.h>

namespace winrt::AIDA64::implementation
{
    struct DisplayModel : DisplayModelT<DisplayModel>
    {
        DisplayModel() = default;

        hstring Name() const noexcept;
        void Name(hstring const& value);

        hstring Caption() const noexcept;
        void Caption(hstring const& value);

        hstring Description() const noexcept;
        void Description(hstring const& value);

        hstring DeviceId() const noexcept;
        void DeviceId(hstring const& value);

        hstring PnpDeviceId() const noexcept;
        void PnpDeviceId(hstring const& value);

        hstring SystemName() const noexcept;
        void SystemName(hstring const& value);

        hstring SystemCreationClassName() const noexcept;
        void SystemCreationClassName(hstring const& value);

        hstring CreationClassName() const noexcept;
        void CreationClassName(hstring const& value);

        hstring MonitorManufacturer() const noexcept;
        void MonitorManufacturer(hstring const& value);

        hstring MonitorType() const noexcept;
        void MonitorType(hstring const& value);

        uint32_t ScreenWidth() const noexcept;
        void ScreenWidth(uint32_t const& value);

        uint32_t ScreenHeight() const noexcept;
        void ScreenHeight(uint32_t const& value);

        hstring InstanceName() const noexcept;
        void InstanceName(hstring const& value);

        bool Active() const noexcept;
        void Active(bool const& value);

        uint32_t MaxHorizontalImageSize() const noexcept;
        void MaxHorizontalImageSize(uint32_t const& value);

        uint32_t MaxVerticalImageSize() const noexcept;
        void MaxVerticalImageSize(uint32_t const& value);

        uint32_t MinRefreshRate() const noexcept;
        void MinRefreshRate(uint32_t const& value);

        uint32_t MaxRefreshRate() const noexcept;
        void MaxRefreshRate(uint32_t const& value);

        uint16_t Availability() const noexcept;
        void Availability(uint16_t const& value);

        bool PowerManagementSupported() const noexcept;
        void PowerManagementSupported(bool const& value);

        bool ErrorCleared() const noexcept;
        void ErrorCleared(bool const& value);

        hstring ErrorDescription() const noexcept;
        void ErrorDescription(hstring const& value);

        uint32_t ConfigManagerErrorCode() const noexcept;
        void ConfigManagerErrorCode(uint32_t const& value);

        bool ConfigManagerUserConfig() const noexcept;
        void ConfigManagerUserConfig(bool const& value);

        hstring InstallDate() const noexcept;
        void InstallDate(hstring const& value);

        uint32_t LastErrorCode() const noexcept;
        void LastErrorCode(uint32_t const& value);

        hstring Status() const noexcept;
        void Status(hstring const& value);

        uint16_t StatusInfo() const noexcept;
        void StatusInfo(uint16_t const& value);

        hstring VideoInputType() const noexcept;
        void VideoInputType(hstring const& value);

    private:
       
        hstring m_name{};
        hstring m_caption{};
        hstring m_description{};
        hstring m_deviceId{};
        hstring m_pnpDeviceId{};
        hstring m_systemName{};
        hstring m_systemCreationClassName{};
        hstring m_creationClassName{};
        hstring m_errorDescription{};
        hstring m_instanceName{};
        hstring m_installDate{};
        hstring m_status{};
        hstring m_videoInputType{};
        hstring m_monitorManufacturer{};
        hstring m_monitorType{};

        uint32_t m_screenWidth{ 0 };
        uint32_t m_screenHeight{ 0 };
        uint32_t m_configManagerErrorCode{ 0 };
        uint32_t m_lastErrorCode{ 0 };
        uint32_t m_maxHorizontalImageSize{ 0 };
        uint32_t m_maxVerticalImageSize{ 0 };
        uint32_t m_minRefreshRate{ 0 };
        uint32_t m_maxRefreshRate{ 0 };

        uint16_t m_availability{ 0 };
        uint16_t m_statusInfo{ 0 };
      

        bool m_active{ false };
        bool m_configManagerUserConfig{ false };
        bool m_errorCleared{ false };
        bool m_powerManagementSupported{ false };
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct DisplayModel : DisplayModelT<DisplayModel, implementation::DisplayModel>
    {
    };
}
