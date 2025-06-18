#pragma once

namespace winrt
{
    using namespace Microsoft::UI::Xaml::Data;
}

namespace winrt::AIDA64::Framework
{
    struct BindableBase : winrt::implements<BindableBase, INotifyPropertyChanged>
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
