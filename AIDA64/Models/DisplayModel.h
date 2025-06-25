#pragma once

#include "DisplayModel.g.h"

namespace winrt::AIDA64::implementation
{
    struct DisplayModel : DisplayModelT<DisplayModel>
    {
        DisplayModel() = default;

        hstring Name() const noexcept;
        void Name(hstring const& value);

        hstring DeviceId() const noexcept;
        void DeviceId(hstring const& value);

        hstring MonitorType() const noexcept;
        void MonitorType(hstring const& value);

        uint32_t ScreenHeight() const noexcept;
        void ScreenHeight(uint32_t const& value);

        uint32_t ScreenWidth() const noexcept;
        void ScreenWidth(uint32_t const& value);

    private:
        hstring m_name{};
        hstring m_deviceId{};
        hstring m_monitorType{};

        uint32_t m_screenHeight{ 0 };
        uint32_t m_screenWidth{ 0 };
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct DisplayModel : DisplayModelT<DisplayModel, implementation::DisplayModel>
    {
    };
}
