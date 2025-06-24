#pragma once

#include "CpuModel.g.h"

namespace winrt::AIDA64::implementation
{
    struct CpuModel : CpuModelT<CpuModel>
    {
        CpuModel() = default;

        // --- Уже было ---
        hstring Name() const noexcept;
        void Name(hstring const& value);

        hstring Manufacturer() const noexcept;
        void Manufacturer(hstring const& value);

        hstring Id() const noexcept;
        void Id(hstring const& value);

        uint32_t CoreCount() const noexcept;
        void CoreCount(uint32_t const& value);

        uint32_t MaxClockSpeed() const noexcept;
        void MaxClockSpeed(uint32_t const& value);

        uint32_t CurrentClockSpeed() const noexcept;
        void CurrentClockSpeed(uint32_t const& value);

        uint16_t LoadPercentage() const noexcept;
        void LoadPercentage(uint16_t const& value);

        uint16_t Architecture() const noexcept;
        void Architecture(uint16_t const& value);

        uint16_t AddressWidth() const noexcept;
        void AddressWidth(uint16_t const& value);

        uint16_t DataWidth() const noexcept;
        void DataWidth(uint16_t const& value);

        // --- Новые свойства WMI ---
        hstring DeviceId() const noexcept;
        void DeviceId(hstring const& value);

        hstring Caption() const noexcept;
        void Caption(hstring const& value);

        hstring Description() const noexcept;
        void Description(hstring const& value);

        uint32_t NumberOfLogicalProcessors() const noexcept;
        void NumberOfLogicalProcessors(uint32_t const& value);

        uint32_t L2CacheSize() const noexcept;      // в KB
        void L2CacheSize(uint32_t const& value);

        uint32_t L3CacheSize() const noexcept;      // в KB
        void L3CacheSize(uint32_t const& value);

        uint16_t Revision() const noexcept;
        void Revision(uint16_t const& value);

        uint16_t Stepping() const noexcept;
        void Stepping(uint16_t const& value);

        uint16_t Family() const noexcept;
        void Family(uint16_t const& value);

        uint16_t CurrentVoltage() const noexcept;   // 0–100 scale
        void CurrentVoltage(uint16_t const& value);

        // можно добавить ещё: SocketDesignation, MaxVoltage, Status и др.

    private:
        // существующие поля
        hstring m_name{};
        hstring m_manufacturer{};
        hstring m_processor_id{};

        uint32_t m_core_count{ 0 };
        uint32_t m_max_clock_speed{ 0 };
        uint32_t m_current_clock_speed{ 0 };

        uint16_t m_load_percentage{ 0 };
        uint16_t m_architecture{ 0 };
        uint16_t m_address_width{ 0 };
        uint16_t m_data_width{ 0 };

        // новые поля
        hstring m_device_id{};
        hstring m_caption{};
        hstring m_description{};

        uint32_t m_logical_processors{ 0 };
        uint32_t m_l2_cache_size{ 0 };
        uint32_t m_l3_cache_size{ 0 };

        uint16_t m_revision{ 0 };
        uint16_t m_stepping{ 0 };
        uint16_t m_family{ 0 };
        uint16_t m_current_voltage{ 0 };
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct CpuModel : CpuModelT<CpuModel, implementation::CpuModel>
    {
    };
}
