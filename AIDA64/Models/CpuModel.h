#pragma once

#include "CpuModel.g.h"

namespace winrt::AIDA64::implementation
{
    struct CpuModel : CpuModelT<CpuModel>
    {
        CpuModel() = default;

        hstring Caption() const noexcept;
        void Caption(hstring const& value);

        hstring Name() const noexcept;
        void Name(hstring const& value);

        hstring Manufacturer() const noexcept;
        void Manufacturer(hstring const& value);

        hstring ProcessorId() const noexcept;
        void ProcessorId(hstring const& value);

        hstring DeviceId() const noexcept;
        void DeviceId(hstring const& value);

        hstring PNPDeviceId() const noexcept;
        void PNPDeviceId(hstring const& value);

        hstring SystemName() const noexcept;
        void SystemName(hstring const& value);

        hstring CreationClassName() const noexcept;
        void CreationClassName(hstring const& value);

        hstring Description() const noexcept;
        void Description(hstring const& value);

        hstring PartNumber() const noexcept;
        void PartNumber(hstring const& value);

        hstring OtherFamilyDescription() const noexcept;
        void OtherFamilyDescription(hstring const& value);

        hstring UniqueId() const noexcept;
        void UniqueId(hstring const& value);

        uint32_t AddressWidth() const noexcept;
        void AddressWidth(uint32_t const& value);

        uint32_t DataWidth() const noexcept;
        void DataWidth(uint32_t const& value);

        uint32_t ExternalClock() const noexcept;         
        void ExternalClock(uint32_t const& value);

        uint32_t CurrentClockSpeed() const noexcept;
        void CurrentClockSpeed(uint32_t const& value);

        uint32_t MaxClockSpeed() const noexcept;
        void MaxClockSpeed(uint32_t const& value);

        uint32_t NumberOfCores() const noexcept;
        void NumberOfCores(uint32_t const& value);

        uint32_t NumberOfLogicalProcessors() const noexcept;
        void NumberOfLogicalProcessors(uint32_t const& value);

        uint32_t L2CacheSize() const noexcept;
        void L2CacheSize(uint32_t const& value);

        uint32_t L3CacheSize() const noexcept;
        void L3CacheSize(uint32_t const& value);

        uint32_t Level() const noexcept;
        void Level(uint32_t const& value);

        uint32_t Revision() const noexcept;
        void Revision(uint32_t const& value);

        uint16_t LoadPercentage() const noexcept;
        void LoadPercentage(uint16_t const& value);

        uint16_t Architecture() const noexcept;
        void Architecture(uint16_t const& value);

        uint16_t Family() const noexcept;
        void Family(uint16_t const& value);

        uint16_t Stepping() const noexcept;
        void Stepping(uint16_t const& value);

        uint16_t CpuStatus() const noexcept;
        void CpuStatus(uint16_t const& value);

        uint16_t CurrentVoltage() const noexcept;
        void CurrentVoltage(uint16_t const& value);

        uint16_t StatusInfo() const noexcept;
        void StatusInfo(uint16_t const& value);

        uint16_t Characteristics() const noexcept;      
        void Characteristics(uint16_t const& value);

        bool PowerManagementSupported() const noexcept;
        void PowerManagementSupported(bool const& value);

        bool ErrorCleared() const noexcept;
        void ErrorCleared(bool const& value);

        Windows::Foundation::Collections::IVector<uint16_t> VoltageCaps() const;
        void VoltageCaps(Windows::Foundation::Collections::IVector<uint16_t> const& value);

        Windows::Foundation::Collections::IVector<uint16_t> PowerManagementCapabilities() const;
        void PowerManagementCapabilities(Windows::Foundation::Collections::IVector<uint16_t> const& value);

        hstring InstallDate() const noexcept;           
        void InstallDate(hstring const& value);

        uint32_t LastErrorCode() const noexcept;
        void LastErrorCode(uint32_t const& value);

        hstring Status() const noexcept;
        void Status(hstring const& value);

        uint16_t UpgradeMethod() const noexcept;
        void UpgradeMethod(uint16_t const& value);

        hstring Role() const noexcept;
        void Role(hstring const& value);

    private:
        
        hstring m_caption{};
        hstring m_name{};
        hstring m_manufacturer{};
        hstring m_processorId{};
        hstring m_deviceId{};
        hstring m_pnpDeviceId{};
        hstring m_systemName{};
        hstring m_creationClassName{};
        hstring m_description{};
        hstring m_partNumber{};
        hstring m_otherFamilyDescription{};
        hstring m_uniqueId{};
        hstring m_installDate{};
        hstring m_status{};
        hstring m_role{};

        uint32_t m_addressWidth{ 0 };
        uint32_t m_dataWidth{ 0 };
        uint32_t m_externalClock{ 0 };
        uint32_t m_currentClockSpeed{ 0 };
        uint32_t m_maxClockSpeed{ 0 };
        uint32_t m_numberOfCores{ 0 };
        uint32_t m_numberOfLogicalProcessors{ 0 };
        uint32_t m_l2CacheSize{ 0 };
        uint32_t m_l3CacheSize{ 0 };
        uint32_t m_level{ 0 };
        uint32_t m_revision{ 0 };
        uint32_t m_lastErrorCode{ 0 };

        uint16_t m_loadPercentage{ 0 };
        uint16_t m_architecture{ 0 };
        uint16_t m_family{ 0 };
        uint16_t m_stepping{ 0 };
        uint16_t m_cpuStatus{ 0 };
        uint16_t m_currentVoltage{ 0 };
        uint16_t m_statusInfo{ 0 };
        uint16_t m_characteristics{ 0 };
        uint16_t m_upgradeMethod{ 0 };

        bool m_powerManagementSupported{ false };
        bool m_errorCleared{ false };

        Windows::Foundation::Collections::IVector<uint16_t> m_voltageCaps{ single_threaded_vector<uint16_t>() };
        Windows::Foundation::Collections::IVector<uint16_t> m_powerManagementCapabilities{ single_threaded_vector<uint16_t>() };
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct CpuModel : CpuModelT<CpuModel, implementation::CpuModel>
    {
    };
}
