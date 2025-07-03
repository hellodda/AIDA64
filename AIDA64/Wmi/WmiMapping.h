#pragma once
#include "WmiObject.h"

#include <Models/CpuModel.h>
#include <Models/DisplayModel.h>
#include <Models/ProcessModel.h>

#include <winrt/AIDA64.h>

#include <wtypes.h>

//------------------------------------------------------------------------------
//-
//------------------------------------------------------------------------------

namespace wmi
{
	template<typename T>
	T from_wmi(IWmiObject const& object);

	template<>
	winrt::AIDA64::CpuModel from_wmi(IWmiObject const& object);

	template<>
	winrt::AIDA64::DisplayModel from_wmi(IWmiObject const& object);
}