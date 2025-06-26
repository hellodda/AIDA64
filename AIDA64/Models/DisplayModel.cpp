#include "pch.h"
#include "DisplayModel.h"
#if __has_include("DisplayModel.g.cpp")
#include "DisplayModel.g.cpp"
#endif

namespace winrt::AIDA64::implementation
{
    hstring DisplayModel::Name() const noexcept { return m_name; }
    void DisplayModel::Name(hstring const& value)
    {
        if (m_name != value) m_name = value;
    }

    hstring DisplayModel::Caption() const noexcept { return m_caption; }
    void DisplayModel::Caption(hstring const& value)
    {
        if (m_caption != value) m_caption = value;
    }

    hstring DisplayModel::Description() const noexcept { return m_description; }
    void DisplayModel::Description(hstring const& value)
    {
        if (m_description != value) m_description = value;
    }

    hstring DisplayModel::DeviceId() const noexcept { return m_deviceId; }
    void DisplayModel::DeviceId(hstring const& value)
    {
        if (m_deviceId != value) m_deviceId = value;
    }

    hstring DisplayModel::PnpDeviceId() const noexcept { return m_pnpDeviceId; }
    void DisplayModel::PnpDeviceId(hstring const& value)
    {
        if (m_pnpDeviceId != value) m_pnpDeviceId = value;
    }

    hstring DisplayModel::SystemName() const noexcept { return m_systemName; }
    void DisplayModel::SystemName(hstring const& value)
    {
        if (m_systemName != value) m_systemName = value;
    }

    hstring DisplayModel::SystemCreationClassName() const noexcept { return m_systemCreationClassName; }
    void DisplayModel::SystemCreationClassName(hstring const& value)
    {
        if (m_systemCreationClassName != value) m_systemCreationClassName = value;
    }

    hstring DisplayModel::CreationClassName() const noexcept { return m_creationClassName; }
    void DisplayModel::CreationClassName(hstring const& value)
    {
        if (m_creationClassName != value) m_creationClassName = value;
    }

    hstring DisplayModel::MonitorManufacturer() const noexcept { return m_monitorManufacturer; }
    void DisplayModel::MonitorManufacturer(hstring const& value)
    {
        if (m_monitorManufacturer != value) m_monitorManufacturer = value;
    }

    hstring DisplayModel::MonitorType() const noexcept { return m_monitorType; }
    void DisplayModel::MonitorType(hstring const& value)
    {
        if (m_monitorType != value) m_monitorType = value;
    }

    uint32_t DisplayModel::ScreenWidth() const noexcept { return m_screenWidth; }
    void DisplayModel::ScreenWidth(uint32_t const& value)
    {
        if (m_screenWidth != value) m_screenWidth = value;
    }

    uint32_t DisplayModel::ScreenHeight() const noexcept { return m_screenHeight; }
    void DisplayModel::ScreenHeight(uint32_t const& value)
    {
        if (m_screenHeight != value) m_screenHeight = value;
    }

    hstring DisplayModel::InstanceName() const noexcept { return m_instanceName; }
    void DisplayModel::InstanceName(hstring const& value)
    {
        if (m_instanceName != value) m_instanceName = value;
    }

    bool DisplayModel::Active() const noexcept { return m_active; }
    void DisplayModel::Active(bool const& value)
    {
        if (m_active != value) m_active = value;
    }

    uint32_t DisplayModel::MaxHorizontalImageSize() const noexcept { return m_maxHorizontalImageSize; }
    void DisplayModel::MaxHorizontalImageSize(uint32_t const& value)
    {
        if (m_maxHorizontalImageSize != value) m_maxHorizontalImageSize = value;
    }

    uint32_t DisplayModel::MaxVerticalImageSize() const noexcept { return m_maxVerticalImageSize; }
    void DisplayModel::MaxVerticalImageSize(uint32_t const& value)
    {
        if (m_maxVerticalImageSize != value) m_maxVerticalImageSize = value;
    }

    uint32_t DisplayModel::MinRefreshRate() const noexcept { return m_minRefreshRate; }
    void DisplayModel::MinRefreshRate(uint32_t const& value)
    {
        if (m_minRefreshRate != value) m_minRefreshRate = value;
    }

    uint32_t DisplayModel::MaxRefreshRate() const noexcept { return m_maxRefreshRate; }
    void DisplayModel::MaxRefreshRate(uint32_t const& value)
    {
        if (m_maxRefreshRate != value) m_maxRefreshRate = value;
    }

    uint16_t DisplayModel::Availability() const noexcept { return m_availability; }
    void DisplayModel::Availability(uint16_t const& value)
    {
        if (m_availability != value) m_availability = value;
    }

    bool DisplayModel::PowerManagementSupported() const noexcept { return m_powerManagementSupported; }
    void DisplayModel::PowerManagementSupported(bool const& value)
    {
        if (m_powerManagementSupported != value) m_powerManagementSupported = value;
    }

    bool DisplayModel::ErrorCleared() const noexcept { return m_errorCleared; }
    void DisplayModel::ErrorCleared(bool const& value)
    {
        if (m_errorCleared != value) m_errorCleared = value;
    }

    hstring DisplayModel::ErrorDescription() const noexcept { return m_errorDescription; }
    void DisplayModel::ErrorDescription(hstring const& value)
    {
        if (m_errorDescription != value) m_errorDescription = value;
    }

    uint32_t DisplayModel::ConfigManagerErrorCode() const noexcept { return m_configManagerErrorCode; }
    void DisplayModel::ConfigManagerErrorCode(uint32_t const& value)
    {
        if (m_configManagerErrorCode != value) m_configManagerErrorCode = value;
    }

    bool DisplayModel::ConfigManagerUserConfig() const noexcept { return m_configManagerUserConfig; }
    void DisplayModel::ConfigManagerUserConfig(bool const& value)
    {
        if (m_configManagerUserConfig != value) m_configManagerUserConfig = value;
    }

    hstring DisplayModel::InstallDate() const noexcept { return m_installDate; }
    void DisplayModel::InstallDate(hstring const& value)
    {
        if (m_installDate != value) m_installDate = value;
    }

    uint32_t DisplayModel::LastErrorCode() const noexcept { return m_lastErrorCode; }
    void DisplayModel::LastErrorCode(uint32_t const& value)
    {
        if (m_lastErrorCode != value) m_lastErrorCode = value;
    }

    hstring DisplayModel::Status() const noexcept { return m_status; }
    void DisplayModel::Status(hstring const& value)
    {
        if (m_status != value) m_status = value;
    }

    uint16_t DisplayModel::StatusInfo() const noexcept { return m_statusInfo; }
    void DisplayModel::StatusInfo(uint16_t const& value)
    {
        if (m_statusInfo != value) m_statusInfo = value;
    }

    hstring DisplayModel::VideoInputType() const noexcept { return m_videoInputType; }
    void DisplayModel::VideoInputType(hstring const& value)
    {
        if (m_videoInputType != value) m_videoInputType = value;
    }
}
