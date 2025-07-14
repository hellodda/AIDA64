#include "pch.h"
#include "ReverseVisibilityConverter.h"

winrt::Windows::Foundation::IInspectable winrt::AIDA64::Convertors::ReverseVisibilityConverter::Convert(winrt::Windows::Foundation::IInspectable const& value, winrt::Windows::UI::Xaml::Interop::TypeName const&, winrt::Windows::Foundation::IInspectable const&, hstring const&)
{
    bool isVisible = unbox_value<bool>(value);
    return box_value(isVisible ? Microsoft::UI::Xaml::Visibility::Collapsed : Microsoft::UI::Xaml::Visibility::Visible);
}