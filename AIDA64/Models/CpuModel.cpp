#include "pch.h"
#include "CpuModel.h"
#if __has_include("CpuModel.g.cpp")
#include "CpuModel.g.cpp"
#endif

namespace winrt::AIDA64::implementation
{
    // --- Существующие свойства ---
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

    // --- Реализация новых свойств WMI ---
    winrt::hstring CpuModel::DeviceId() const noexcept
    {
        return m_device_id;
    }

    void CpuModel::DeviceId(winrt::hstring const& value)
    {
        if (m_device_id != value)
        {
            m_device_id = value;
        }
    }

    winrt::hstring CpuModel::Caption() const noexcept
    {
        return m_caption;
    }

    void CpuModel::Caption(winrt::hstring const& value)
    {
        if (m_caption != value)
        {
            m_caption = value;
        }
    }

    winrt::hstring CpuModel::Description() const noexcept
    {
        return m_description;
    }

    void CpuModel::Description(winrt::hstring const& value)
    {
        if (m_description != value)
        {
            m_description = value;
        }
    }

    uint32_t CpuModel::NumberOfLogicalProcessors() const noexcept
    {
        return m_logical_processors;
    }

    void CpuModel::NumberOfLogicalProcessors(uint32_t const& value)
    {
        if (m_logical_processors != value)
        {
            m_logical_processors = value;
        }
    }

    uint32_t CpuModel::L2CacheSize() const noexcept
    {
        return m_l2_cache_size;
    }

    void CpuModel::L2CacheSize(uint32_t const& value)
    {
        if (m_l2_cache_size != value)
        {
            m_l2_cache_size = value;
        }
    }

    uint32_t CpuModel::L3CacheSize() const noexcept
    {
        return m_l3_cache_size;
    }

    void CpuModel::L3CacheSize(uint32_t const& value)
    {
        if (m_l3_cache_size != value)
        {
            m_l3_cache_size = value;
        }
    }

    uint16_t CpuModel::Revision() const noexcept
    {
        return m_revision;
    }

    void CpuModel::Revision(uint16_t const& value)
    {
        if (m_revision != value)
        {
            m_revision = value;
        }
    }

    uint16_t CpuModel::Stepping() const noexcept
    {
        return m_stepping;
    }

    void CpuModel::Stepping(uint16_t const& value)
    {
        if (m_stepping != value)
        {
            m_stepping = value;
        }
    }

    uint16_t CpuModel::Family() const noexcept
    {
        return m_family;
    }

    void CpuModel::Family(uint16_t const& value)
    {
        if (m_family != value)
        {
            m_family = value;
        }
    }

    uint16_t CpuModel::CurrentVoltage() const noexcept
    {
        return m_current_voltage;
    }

    void CpuModel::CurrentVoltage(uint16_t const& value)
    {
        if (m_current_voltage != value)
        {
            m_current_voltage = value;
        }
    }
}
