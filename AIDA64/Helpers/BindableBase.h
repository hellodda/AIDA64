#pragma once
#include <winrt/Microsoft.UI.Xaml.Data.h>

namespace winrt
{
    using namespace winrt::Microsoft::UI::Xaml::Data;
    using namespace winrt::Windows::Foundation;
}

namespace winrt::AIDA64::Helpers
{
    struct BindableBase : winrt::implements<BindableBase, winrt::IInspectable>
    {
        BindableBase() = default;

        winrt::event_token PropertyChanged(winrt::PropertyChangedEventHandler const& handler);

        void PropertyChanged(winrt::event_token const& token) noexcept;

    protected:
        void RaisePropertyChanged(winrt::hstring const& propertyName);

    private:
        winrt::event<winrt::PropertyChangedEventHandler> m_propertyChanged;
    };
}