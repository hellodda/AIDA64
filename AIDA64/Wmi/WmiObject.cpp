#include "pch.h"
#include "WmiObject.h"

#include <Framework/Utilities.h>

namespace wmi
{
    bool try_get_property(std::wstring const& property_name, winrt::com_ptr<IWbemClassObject> const& object, _variant_t& variant)
    {
        return SUCCEEDED(object->Get(property_name.c_str(), NULL, &variant, NULL, NULL));
    }

    WmiObject::WmiObject(IWbemClassObject* object)
    {
        m_object.copy_from(object);
    }
    std::optional<property_value_t> wmi::WmiObject::get_property(std::wstring name) const
	{
        _variant_t var;
        
        if (!try_get_property(name, m_object, var))
        {
            return std::nullopt;
        }

        switch (var.vt)
        {
        case VT_BOOL:
            return property_value_t{ var.boolVal };

        case VT_I1: 
            return property_value_t{ static_cast<int8_t>(var.cVal) };

        case VT_UI1:
            return property_value_t{ static_cast<uint8_t>(var.bVal) };

        case VT_I2: 
            return property_value_t{ static_cast<int16_t>(var.iVal) };

        case VT_UI2: 
            return property_value_t{ static_cast<uint16_t>(var.uiVal) };

        case VT_I4:
        case VT_INT:
            return property_value_t{ static_cast<int32_t>(var.intVal) };

        case VT_UI4:
        case VT_UINT:
            return property_value_t{ static_cast<uint32_t>(var.uintVal) };

        case VT_BSTR:
            if (var.bstrVal)
                return property_value_t{ std::wstring{ var.bstrVal } };
            else
                return std::nullopt;

        default:
            return std::nullopt;
        }
	}
}
