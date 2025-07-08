#pragma once
#include <winrt/Microsoft.UI.Xaml.Data.h>

namespace winrt::AIDA64::Convertors
{
    struct VisibilityConverter : winrt::implements<VisibilityConverter, Microsoft::UI::Xaml::Data::IValueConverter>
    {
        winrt::Windows::Foundation::IInspectable Convert(
            winrt::Windows::Foundation::IInspectable const& value,
            winrt::Windows::UI::Xaml::Interop::TypeName const&,
            winrt::Windows::Foundation::IInspectable const&,
            hstring const&
        );

        winrt::Windows::Foundation::IInspectable ConvertBack(...) { return nullptr; }
    };
}