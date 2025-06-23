#include "pch.h"
#include "CpuModel.h"
#if __has_include("CpuModel.g.cpp")
#include "CpuModel.g.cpp"
#endif

namespace winrt::AIDA64::implementation
{
    winrt::hstring CpuModel::Name() const noexcept
    {
        return m_name;
    }

    void CpuModel::Name(winrt::hstring const& value)
    {
        if (m_name != value)
        {
            m_name = value;
            
        }
    }

    winrt::hstring CpuModel::Manufacturer() const noexcept
    {
        return m_manufacturer;
    }

    void CpuModel::Manufacturer(winrt::hstring const& value)
    {
        if (m_manufacturer != value)
        {
            m_manufacturer = value;
        }
    }

    winrt::hstring CpuModel::Id() const noexcept
    {
        return m_processor_id;
    }

    void CpuModel::Id(winrt::hstring const& value)
    {
        if (m_processor_id != value)
        {
            m_processor_id = value;
        }
    }

    uint32_t CpuModel::CoreCount() const noexcept
    {
        return m_core_count;
    }

    void CpuModel::CoreCount(uint32_t const& value)
    {
        if (m_core_count != value)
        {
            m_core_count = value;
        }
    }

    uint32_t CpuModel::MaxClockSpeed() const noexcept
    {
        return m_max_clock_speed;
    }

    void CpuModel::MaxClockSpeed(uint32_t const& value)
    {
        if (m_max_clock_speed != value)
        {
            m_max_clock_speed = value;
        }
    }

    uint32_t CpuModel::CurrentClockSpeed() const noexcept
    {
        return m_current_clock_speed;
    }

    void CpuModel::CurrentClockSpeed(uint32_t const& value)
    {
        if (m_current_clock_speed != value)
        {
            m_current_clock_speed = value;
        }
    }

    uint16_t CpuModel::LoadPercentage() const noexcept
    {
        return m_load_percentage;
    }

    void CpuModel::LoadPercentage(uint16_t const& value)
    {
        if (m_load_percentage != value)
        {
            m_load_percentage = value;
        }
    }

    uint16_t CpuModel::Architecture() const noexcept
    {
        return m_architecture;
    }

    void CpuModel::Architecture(uint16_t const& value)
    {
        if (m_architecture != value)
        {
            m_architecture = value;
        }
    }

    uint16_t CpuModel::AddressWidth() const noexcept
    {
        return m_address_width;
    }

    void CpuModel::AddressWidth(uint16_t const& value)
    {
        if (m_address_width != value)
        {
            m_address_width = value;
        }
    }

    uint16_t CpuModel::DataWidth() const noexcept
    {
        return m_data_width;
    }

    void CpuModel::DataWidth(uint16_t const& value)
    {
        if (m_data_width != value)
        {
            m_data_width = value;
        }
    }
}
