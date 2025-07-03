#pragma once
#include "IWmiObject.h"

#include <variant>

namespace wmi
{
	static bool try_get_property(std::wstring const& property_name, winrt::com_ptr<IWbemClassObject> const& object, _variant_t& variant);

	struct WmiObject : IWmiObject
	{
		WmiObject(winrt::com_ptr<IWbemClassObject> object) : m_object(std::move(object)) {}
		WmiObject(IWbemClassObject* object);
		~WmiObject() = default;

		std::optional<property_value_t> get_property(std::wstring name) const override;
	private:
		winrt::com_ptr<IWbemClassObject> m_object;
	};
}