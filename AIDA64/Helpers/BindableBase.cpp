#include "pch.h"
#include "BindableBase.h"
#if __has_include("BindableBase.g.cpp")
#include "BindableBase.g.cpp"
#endif

namespace winrt::AIDA64::implementation
{
    winrt::event_token BindableBase::PropertyChanged(winrt::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void BindableBase::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
    void BindableBase::RaisePropertyChanged(winrt::hstring const& propertyName)
    {
        m_propertyChanged(*this, winrt::PropertyChangedEventArgs{ propertyName });
    }
}
