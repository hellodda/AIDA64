#pragma once

#include "MemoryModel.g.h"

namespace winrt::AIDA64::implementation
{
    struct MemoryModel : MemoryModelT<MemoryModel>
    {
        winrt::hstring BankLabel() const noexcept;
        void BankLabel(winrt::hstring const& value);

        uint64_t Capacity() const noexcept;
        void Capacity(uint64_t value);

        winrt::hstring CapacityStr() const noexcept;
        void CapacityStr(winrt::hstring const& value);

        uint16_t DataWidth() const noexcept;
        void DataWidth(uint16_t value);

        uint16_t TotalWidth() const noexcept;
        void TotalWidth(uint16_t value);

        uint32_t Speed() const noexcept;
        void Speed(uint32_t value);

        winrt::hstring Manufacturer() const noexcept;
        void Manufacturer(winrt::hstring const& value);

        winrt::hstring SerialNumber() const noexcept;
        void SerialNumber(winrt::hstring const& value);

        winrt::hstring PartNumber() const noexcept;
        void PartNumber(winrt::hstring const& value);

        uint16_t FormFactor() const noexcept;
        void FormFactor(uint16_t value);

        uint16_t MemoryType() const noexcept;
        void MemoryType(uint16_t value);

        uint8_t SMBIOSMemoryType() const noexcept;
        void SMBIOSMemoryType(uint8_t value);

        winrt::hstring Tag() const noexcept;
        void Tag(winrt::hstring const& value);

        winrt::hstring DeviceLocator() const noexcept;
        void DeviceLocator(winrt::hstring const& value);

    private:
        winrt::hstring m_bankLabel{};
        uint64_t m_capacity{};
        winrt::hstring m_capacityStr{};
        uint16_t m_dataWidth{};
        uint16_t m_totalWidth{};
        uint32_t m_speed{};
        winrt::hstring m_manufacturer{};
        winrt::hstring m_serialNumber{};
        winrt::hstring m_partNumber{};
        uint16_t m_formFactor{};
        uint16_t m_memoryType{};
        uint8_t m_smbiosMemoryType{};
        winrt::hstring m_tag{};
        winrt::hstring m_deviceLocator{};
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct MemoryModel : MemoryModelT<MemoryModel, implementation::MemoryModel>
    {
    };
}
