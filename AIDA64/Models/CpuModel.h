#pragma once

#include "CpuModel.g.h"

namespace winrt::AIDA64::implementation
{
    struct CpuModel : CpuModelT<CpuModel>
    {
        CpuModel() = default;

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

    private:

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
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct CpuModel : CpuModelT<CpuModel, implementation::CpuModel>
    {
    };
}
