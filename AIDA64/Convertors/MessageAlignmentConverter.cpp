#include "pch.h"
#include "MessageAlignmentConverter.h"

winrt::Windows::Foundation::IInspectable winrt::AIDA64::Convertors::MessageAlignmentConverter::Convert(winrt::Windows::Foundation::IInspectable const& value, winrt::Windows::UI::Xaml::Interop::TypeName const&, winrt::Windows::Foundation::IInspectable const&, hstring const&)
{
    bool isSent = unbox_value<bool>(value);
    return box_value(isSent ? Microsoft::UI::Xaml::HorizontalAlignment::Right : Microsoft::UI::Xaml::HorizontalAlignment::Left);
}