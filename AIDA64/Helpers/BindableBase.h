#pragma once

#include "BindableBase.g.h"

namespace winrt
{
    using namespace winrt::Microsoft::UI::Xaml::Data;
}

namespace winrt::AIDA64::implementation
{
    struct BindableBase : BindableBaseT<BindableBase, INotifyPropertyChanged>
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

namespace winrt::AIDA64::factory_implementation
{
    struct BindableBase : BindableBaseT<BindableBase, implementation::BindableBase>
    {
    };
}
