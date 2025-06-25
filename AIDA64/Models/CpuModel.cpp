#include "pch.h"
#include "CpuModel.h"
#if __has_include("CpuModel.g.cpp")
#include "CpuModel.g.cpp"
#endif

using namespace winrt;
using namespace winrt::Windows::Foundation::Collections;

namespace winrt::AIDA64::implementation
{
    hstring CpuModel::Caption() const noexcept { return m_caption; }
    void CpuModel::Caption(hstring const& value)
    {
        if (m_caption != value) m_caption = value;
    }

    hstring CpuModel::Name() const noexcept { return m_name; }
    void CpuModel::Name(hstring const& value)
    {
        if (m_name != value) m_name = value;
    }

    hstring CpuModel::Manufacturer() const noexcept { return m_manufacturer; }
    void CpuModel::Manufacturer(hstring const& value)
    {
        if (m_manufacturer != value) m_manufacturer = value;
    }

    hstring CpuModel::ProcessorId() const noexcept { return m_processorId; }
    void CpuModel::ProcessorId(hstring const& value)
    {
        if (m_processorId != value) m_processorId = value;
    }

    hstring CpuModel::DeviceId() const noexcept { return m_deviceId; }
    void CpuModel::DeviceId(hstring const& value)
    {
        if (m_deviceId != value) m_deviceId = value;
    }

    hstring CpuModel::PNPDeviceId() const noexcept { return m_pnpDeviceId; }
    void CpuModel::PNPDeviceId(hstring const& value)
    {
        if (m_pnpDeviceId != value) m_pnpDeviceId = value;
    }

    hstring CpuModel::SystemName() const noexcept { return m_systemName; }
    void CpuModel::SystemName(hstring const& value)
    {
        if (m_systemName != value) m_systemName = value;
    }

    hstring CpuModel::CreationClassName() const noexcept { return m_creationClassName; }
    void CpuModel::CreationClassName(hstring const& value)
    {
        if (m_creationClassName != value) m_creationClassName = value;
    }

    hstring CpuModel::Description() const noexcept { return m_description; }
    void CpuModel::Description(hstring const& value)
    {
        if (m_description != value) m_description = value;
    }

    hstring CpuModel::PartNumber() const noexcept { return m_partNumber; }
    void CpuModel::PartNumber(hstring const& value)
    {
        if (m_partNumber != value) m_partNumber = value;
    }

    hstring CpuModel::OtherFamilyDescription() const noexcept { return m_otherFamilyDescription; }
    void CpuModel::OtherFamilyDescription(hstring const& value)
    {
        if (m_otherFamilyDescription != value) m_otherFamilyDescription = value;
    }

    hstring CpuModel::UniqueId() const noexcept { return m_uniqueId; }
    void CpuModel::UniqueId(hstring const& value)
    {
        if (m_uniqueId != value) m_uniqueId = value;
    }

    hstring CpuModel::InstallDate() const noexcept { return m_installDate; }
    void CpuModel::InstallDate(hstring const& value)
    {
        if (m_installDate != value) m_installDate = value;
    }

    hstring CpuModel::Status() const noexcept { return m_status; }
    void CpuModel::Status(hstring const& value)
    {
        if (m_status != value) m_status = value;
    }

    hstring CpuModel::Role() const noexcept { return m_role; }
    void CpuModel::Role(hstring const& value)
    {
        if (m_role != value) m_role = value;
    }

    uint32_t CpuModel::AddressWidth() const noexcept { return m_addressWidth; }
    void CpuModel::AddressWidth(uint32_t const& value)
    {
        if (m_addressWidth != value) m_addressWidth = value;
    }

    uint32_t CpuModel::DataWidth() const noexcept { return m_dataWidth; }
    void CpuModel::DataWidth(uint32_t const& value)
    {
        if (m_dataWidth != value) m_dataWidth = value;
    }

    uint32_t CpuModel::ExternalClock() const noexcept { return m_externalClock; }
    void CpuModel::ExternalClock(uint32_t const& value)
    {
        if (m_externalClock != value) m_externalClock = value;
    }

    uint32_t CpuModel::CurrentClockSpeed() const noexcept { return m_currentClockSpeed; }
    void CpuModel::CurrentClockSpeed(uint32_t const& value)
    {
        if (m_currentClockSpeed != value) m_currentClockSpeed = value;
    }

    uint32_t CpuModel::MaxClockSpeed() const noexcept { return m_maxClockSpeed; }
    void CpuModel::MaxClockSpeed(uint32_t const& value)
    {
        if (m_maxClockSpeed != value) m_maxClockSpeed = value;
    }

    uint32_t CpuModel::NumberOfCores() const noexcept { return m_numberOfCores; }
    void CpuModel::NumberOfCores(uint32_t const& value)
    {
        if (m_numberOfCores != value) m_numberOfCores = value;
    }

    uint32_t CpuModel::NumberOfLogicalProcessors() const noexcept { return m_numberOfLogicalProcessors; }
    void CpuModel::NumberOfLogicalProcessors(uint32_t const& value)
    {
        if (m_numberOfLogicalProcessors != value) m_numberOfLogicalProcessors = value;
    }

    uint32_t CpuModel::L2CacheSize() const noexcept { return m_l2CacheSize; }
    void CpuModel::L2CacheSize(uint32_t const& value)
    {
        if (m_l2CacheSize != value) m_l2CacheSize = value;
    }

    uint32_t CpuModel::L3CacheSize() const noexcept { return m_l3CacheSize; }
    void CpuModel::L3CacheSize(uint32_t const& value)
    {
        if (m_l3CacheSize != value) m_l3CacheSize = value;
    }

    uint32_t CpuModel::Level() const noexcept { return m_level; }
    void CpuModel::Level(uint32_t const& value)
    {
        if (m_level != value) m_level = value;
    }

    uint32_t CpuModel::Revision() const noexcept { return m_revision; }
    void CpuModel::Revision(uint32_t const& value)
    {
        if (m_revision != value) m_revision = value;
    }

    uint32_t CpuModel::LastErrorCode() const noexcept { return m_lastErrorCode; }
    void CpuModel::LastErrorCode(uint32_t const& value)
    {
        if (m_lastErrorCode != value) m_lastErrorCode = value;
    }

    uint16_t CpuModel::LoadPercentage() const noexcept { return m_loadPercentage; }
    void CpuModel::LoadPercentage(uint16_t const& value)
    {
        if (m_loadPercentage != value) m_loadPercentage = value;
    }

    uint16_t CpuModel::Architecture() const noexcept { return m_architecture; }
    void CpuModel::Architecture(uint16_t const& value)
    {
        if (m_architecture != value) m_architecture = value;
    }

    uint16_t CpuModel::Family() const noexcept { return m_family; }
    void CpuModel::Family(uint16_t const& value)
    {
        if (m_family != value) m_family = value;
    }

    uint16_t CpuModel::Stepping() const noexcept { return m_stepping; }
    void CpuModel::Stepping(uint16_t const& value)
    {
        if (m_stepping != value) m_stepping = value;
    }

    uint16_t CpuModel::CpuStatus() const noexcept { return m_cpuStatus; }
    void CpuModel::CpuStatus(uint16_t const& value)
    {
        if (m_cpuStatus != value) m_cpuStatus = value;
    }

    uint16_t CpuModel::CurrentVoltage() const noexcept { return m_currentVoltage; }
    void CpuModel::CurrentVoltage(uint16_t const& value)
    {
        if (m_currentVoltage != value) m_currentVoltage = value;
    }

    uint16_t CpuModel::StatusInfo() const noexcept { return m_statusInfo; }
    void CpuModel::StatusInfo(uint16_t const& value)
    {
        if (m_statusInfo != value) m_statusInfo = value;
    }

    uint16_t CpuModel::Characteristics() const noexcept { return m_characteristics; }
    void CpuModel::Characteristics(uint16_t const& value)
    {
        if (m_characteristics != value) m_characteristics = value;
    }

    uint16_t CpuModel::UpgradeMethod() const noexcept { return m_upgradeMethod; }
    void CpuModel::UpgradeMethod(uint16_t const& value)
    {
        if (m_upgradeMethod != value) m_upgradeMethod = value;
    }

    bool CpuModel::PowerManagementSupported() const noexcept { return m_powerManagementSupported; }
    void CpuModel::PowerManagementSupported(bool const& value)
    {
        if (m_powerManagementSupported != value) m_powerManagementSupported = value;
    }

    bool CpuModel::ErrorCleared() const noexcept { return m_errorCleared; }
    void CpuModel::ErrorCleared(bool const& value)
    {
        if (m_errorCleared != value) m_errorCleared = value;
    }

    IVector<uint16_t> CpuModel::VoltageCaps() const
    {
        return m_voltageCaps;
    }
    void CpuModel::VoltageCaps(IVector<uint16_t> const& value)
    {
        m_voltageCaps = value;
    }

    IVector<uint16_t> CpuModel::PowerManagementCapabilities() const
    {
        return m_powerManagementCapabilities;
    }
    void CpuModel::PowerManagementCapabilities(IVector<uint16_t> const& value)
    {
        m_powerManagementCapabilities = value;
    }
}
