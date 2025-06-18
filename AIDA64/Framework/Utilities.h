#pragma once
#include "pch.h"
#include <Models/ProcessModel.h>

//-----------------------------------------------------------------
//-
//-		helper functions for defining types
//-
//-----------------------------------------------------------------

bool is_integer(VARTYPE const& type)
{
	return (type == VT_I4 || type == VT_UI4);
}

bool is_string(VARTYPE const& type)
{
	return type == VT_BSTR;
}

bool is_boolean(VARTYPE const& type)
{
	return type == VT_BOOL;
}

//-----------------------------------------------------------------
//-
//-		Mapping : VARIANT to Models
//-
//-----------------------------------------------------------------

template<typename T>
T from_wbem(winrt::com_ptr<IWbemClassObject> const& object);

template<>
winrt::AIDA64::ProcessModel from_wbem(winrt::com_ptr<IWbemClassObject> const& object)
{
	winrt::AIDA64::ProcessModel model{};
	VARIANT var;

	//process name \/
	if (SUCCEEDED(object->Get(L"Name", NULL, &var, NULL, NULL)))
	{
		if (is_string(var.vt))
			model.Name(var.bstrVal);
		VariantClear(&var);
	}

	//process id \/
	if (SUCCEEDED(object->Get(L"ProcessId", NULL, &var, NULL, NULL)))
	{
		if (is_integer(var.vt))
			model.Id(var.uintVal);
		VariantClear(&var);
	}

	//thread count
	if (SUCCEEDED(object->Get(L"ThreadCount", NULL, &var, NULL, NULL)))
	{
		if (is_integer(var.vt))
			model.ThreadCount(var.uintVal);
		VariantClear(&var);
	}

	return model;
}
