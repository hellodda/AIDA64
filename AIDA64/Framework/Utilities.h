#pragma once
#include <Models/CpuModel.h>
#include <Models/ProcessModel.h>
#include <WMIDataContext.h>
#include <winrt/Windows.UI.Xaml.Interop.h>

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
		this->view_model = box_value(view_model);
		this->page_type = xaml_typename<pageT>();
		this->tag = tag;
	}

	winrt::IInspectable view_model;
	Windows::UI::Xaml::Interop::TypeName page_type;
	winrt::hstring tag;
};


template<typename T>
T exchange_ptr(winrt::com_ptr<T> ptr)
{
	return *ptr.get();
}


IAsyncAction mta_context(std::function<void()> const& action);

std::shared_ptr<AIDA64::Framework::WmiDataContext> get_mta_wmi_context();

//don't use in ui context
void wait(std::function<IAsyncAction()> action);

//-----------------------------------------------------------------
//-
//-		helpers for COM
//-
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

//-----------------------------------------------------------------
//-
//-		helper functions for defining types
//-
//-----------------------------------------------------------------

bool is_integer(VARTYPE const& type);
bool is_string(VARTYPE const& type);
bool is_boolean(VARTYPE const& type);
bool try_get_property(std::wstring const& property_name, winrt::com_ptr<IWbemClassObject> const& object, _variant_t& variant);

//-----------------------------------------------------------------
//-
//-		Mapping : VARIANT to Models
//-
//-----------------------------------------------------------------

template<typename T>
T from_wbem(winrt::com_ptr<IWbemClassObject> const& object);

template<>
winrt::AIDA64::ProcessModel from_wbem(winrt::com_ptr<IWbemClassObject> const& object);

template<>
winrt::AIDA64::CpuModel from_wbem(winrt::com_ptr<IWbemClassObject> const& object);