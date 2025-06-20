#include "pch.h"
#include "ProcessorModel.h"
#if __has_include("ProcessorModel.g.cpp")
#include "ProcessorModel.g.cpp"
#endif

namespace winrt::AIDA64::implementation
{
    hstring ProcessorModel::Name() const noexcept
    {
        return m_name;
    }

    void ProcessorModel::Name(hstring const& value)
    {
        if (m_name != value)
        {
            m_name = value;
        }
    }

    hstring ProcessorModel::Manufacturer() const noexcept {
        return m_manufacturer;
    }

    void ProcessorModel::Manufacturer(hstring const& value)
    {
        if (m_manufacturer != value)
        {
            m_manufacturer = value;
        }
    }

    hstring ProcessorModel::Id() const noexcept {
        return m_processor_id;
    }

    void ProcessorModel::Id(hstring const& value)
    {
        if (m_processor_id != value)
        {
            m_processor_id = value;
        }
    }

    uint32_t ProcessorModel::CoreCount() const noexcept
    {
        return m_core_count;
    }

    void ProcessorModel::CoreCount(uint32_t const& value)
    {
        if (m_core_count != value)
        {
            m_core_count = value;
        }
    }

    uint32_t ProcessorModel::MaxClockSpeed() const noexcept
    {
        return m_max_clock_speed;
    }

    void ProcessorModel::MaxClockSpeed(uint32_t const& value)
    {
        if (m_max_clock_speed != value) 
        {
            m_max_clock_speed = value;
        }
    }

    uint32_t ProcessorModel::CurrentClockSpeed() const noexcept
    {
        return m_current_clock_speed;
    }

    void ProcessorModel::CurrentClockSpeed(uint32_t const& value)
    {
        if (m_current_clock_speed != value)
        {
            m_current_clock_speed = value;
        }
    }

    uint16_t ProcessorModel::LoadPercentage() const noexcept {
        return m_load_percentage;
    }

    void ProcessorModel::LoadPercentage(uint16_t const& value)
    {
        if (m_load_percentage != value)
        {
            m_load_percentage = value;
        }
    }

    uint16_t ProcessorModel::Architecture() const noexcept
    {
        return m_architecture;
    }

    void ProcessorModel::Architecture(uint16_t const& value)
    {
        if (m_architecture != value) {
            m_architecture = value;
        }
    }

    uint16_t ProcessorModel::AddressWidth() const noexcept
    {
        return m_address_width;
    }

    void ProcessorModel::AddressWidth(uint16_t const& value)
    {
        if (m_address_width != value)
        {
            m_address_width = value;
        }
    }

    uint16_t ProcessorModel::DataWidth() const noexcept
    {
        return m_data_width;
    }

    void ProcessorModel::DataWidth(uint16_t const& value)
    {
        if (m_data_width != value) {
            m_data_width = value;
        }
    }
}
