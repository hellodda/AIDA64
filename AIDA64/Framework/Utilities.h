#pragma once
#include "pch.h"
#include <Models/ProcessModel.h>

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
bool try_get_property(std::wstring const& property_name, winrt::com_ptr<IWbemClassObject> const& object, VARIANT& variant);

//-----------------------------------------------------------------
//-
//-		Mapping : VARIANT to Models
//-
//-----------------------------------------------------------------

template<typename T>
T from_wbem(winrt::com_ptr<IWbemClassObject> const& object);

template<>
winrt::AIDA64::ProcessModel from_wbem(winrt::com_ptr<IWbemClassObject> const& object);
