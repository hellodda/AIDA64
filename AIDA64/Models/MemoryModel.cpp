#include "pch.h"
#include "MemoryModel.h"
#if __has_include("MemoryModel.g.cpp")
#include "MemoryModel.g.cpp"
#endif

namespace winrt::AIDA64::implementation
{
    hstring MemoryModel::BankLabel() const noexcept { return m_bankLabel; }
    void MemoryModel::BankLabel(hstring const& value)
    {
        if (m_bankLabel != value) m_bankLabel = value;
    }

    uint64_t MemoryModel::Capacity() const noexcept { return m_capacity; }
    void MemoryModel::Capacity(uint64_t value)
    {
        if (m_capacity != value) m_capacity = value;
    }

    hstring MemoryModel::CapacityStr() const noexcept { return m_capacityStr; }
    void MemoryModel::CapacityStr(hstring const& value)
    {
        if (m_capacityStr != value) m_capacityStr = value;
    }

    uint16_t MemoryModel::DataWidth() const noexcept { return m_dataWidth; }
    void MemoryModel::DataWidth(uint16_t value)
    {
        if (m_dataWidth != value) m_dataWidth = value;
    }

    uint16_t MemoryModel::TotalWidth() const noexcept { return m_totalWidth; }
    void MemoryModel::TotalWidth(uint16_t value)
    {
        if (m_totalWidth != value) m_totalWidth = value;
    }

    uint32_t MemoryModel::Speed() const noexcept { return m_speed; }
    void MemoryModel::Speed(uint32_t value)
    {
        if (m_speed != value) m_speed = value;
    }

    hstring MemoryModel::Manufacturer() const noexcept { return m_manufacturer; }
    void MemoryModel::Manufacturer(hstring const& value)
    {
        if (m_manufacturer != value) m_manufacturer = value;
    }

    hstring MemoryModel::SerialNumber() const noexcept { return m_serialNumber; }
    void MemoryModel::SerialNumber(hstring const& value)
    {
        if (m_serialNumber != value) m_serialNumber = value;
    }

    hstring MemoryModel::PartNumber() const noexcept { return m_partNumber; }
    void MemoryModel::PartNumber(hstring const& value)
    {
        if (m_partNumber != value) m_partNumber = value;
    }

    uint16_t MemoryModel::FormFactor() const noexcept { return m_formFactor; }
    void MemoryModel::FormFactor(uint16_t value)
    {
        if (m_formFactor != value) m_formFactor = value;
    }

    uint16_t MemoryModel::MemoryType() const noexcept { return m_memoryType; }
    void MemoryModel::MemoryType(uint16_t value)
    {
        if (m_memoryType != value) m_memoryType = value;
    }

    uint8_t MemoryModel::SMBIOSMemoryType() const noexcept { return m_smbiosMemoryType; }
    void MemoryModel::SMBIOSMemoryType(uint8_t value)
    {
        if (m_smbiosMemoryType != value) m_smbiosMemoryType = value;
    }

    hstring MemoryModel::Tag() const noexcept { return m_tag; }
    void MemoryModel::Tag(hstring const& value)
    {
        if (m_tag != value) m_tag = value;
    }

    hstring MemoryModel::DeviceLocator() const noexcept { return m_deviceLocator; }
    void MemoryModel::DeviceLocator(hstring const& value)
    {
        if (m_deviceLocator != value) m_deviceLocator = value;
    }
}
