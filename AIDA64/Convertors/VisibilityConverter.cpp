#include "pch.h"
#include "VisibilityConverter.h"

winrt::Windows::Foundation::IInspectable winrt::AIDA64::Convertors::VisibilityConverter::Convert(winrt::Windows::Foundation::IInspectable const& value, winrt::Windows::UI::Xaml::Interop::TypeName const&, winrt::Windows::Foundation::IInspectable const&, hstring const&)
{
    bool isVisible = unbox_value<bool>(value);
    return box_value(isVisible ? Microsoft::UI::Xaml::Visibility::Visible : Microsoft::UI::Xaml::Visibility::Collapsed);
}