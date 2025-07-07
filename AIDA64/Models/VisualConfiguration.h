#pragma once

#include "VisualConfiguration.g.h"

namespace winrt::AIDA64::implementation
{
    struct VisualConfiguration : VisualConfigurationT<VisualConfiguration>
    {
        VisualConfiguration() = default;

        winrt::hstring ImagePath() const noexcept;
        void ImagePath(winrt::hstring const& value);

        winrt::hstring Value() const noexcept;
        void Value(winrt::hstring const& value);

    private:

        winrt::hstring m_value{};
        winrt::hstring m_imagePath{};
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct VisualConfiguration : VisualConfigurationT<VisualConfiguration, implementation::VisualConfiguration>
    {
    };
}
