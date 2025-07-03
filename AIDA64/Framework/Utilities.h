#pragma once

#include <Models/CpuModel.h>
#include <Models/ProcessModel.h>
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <Wmi/IWmiDataContext.h>
#include <Framework/TaskScheduler.h>

//------------------------------------------------------------------
//- other helpers \/
//------------------------------------------------------------------

// nav helper :)
struct page_data_t
{
    page_data_t() = default;

    template<typename view_modelT, typename pageT>
    page_data_t(winrt::hstring const& tag, view_modelT view_model, pageT page)
    {
        this->view_model = winrt::box_value(view_model);
        this->page_type = winrt::xaml_typename<pageT>();
        this->tag = tag;
    }

    page_data_t(page_data_t const& other) : tag(other.tag), view_model(other.view_model), page_type(other.page_type) {}

    winrt::Windows::Foundation::IInspectable view_model;
    winrt::Windows::UI::Xaml::Interop::TypeName page_type;
    winrt::hstring tag;
};

template<typename controlT, typename propertyT>
winrt::Microsoft::UI::Xaml::DependencyProperty register_property(winrt::hstring name, winrt::Microsoft::UI::Xaml::PropertyMetadata metadata = nullptr)
{
    return winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
        name,
        winrt::xaml_typename<propertyT>(),
        winrt::xaml_typename<controlT>(),
        metadata
    );
}

template<typename T>
T exchange_ptr(winrt::com_ptr<T> ptr)
{
    return *ptr.get();
}

template<typename T>
T& get_instance()
{
    static T singleton_instance;
    return singleton_instance;
}

//------------------------------------------------------------------
//
//------------------------------------------------------------------

winrt::Windows::Foundation::IAsyncAction mta_context(std::function<void()> const& action);

std::shared_ptr<wmi::IWmiDataContext> get_mta_wmi_context();

// don't use in UI context
void wait(std::function<winrt::Windows::Foundation::IAsyncAction()> action);

//-----------------------------------------------------------------
//- helpers for COM
//-----------------------------------------------------------------

template<winrt::apartment_type type>
struct apartment_guard
{
    apartment_guard()
    {
        winrt::init_apartment(type);
    }
    ~apartment_guard()
    {
        winrt::uninit_apartment();
    }
};

namespace this_thread
{
    bool is_mta();
    bool is_sta();
    APTTYPE get_apartment_type();
}
