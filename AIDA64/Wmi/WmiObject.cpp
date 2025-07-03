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
        object->AddRef();
        m_object.attach(object);
    }
    std::optional<value_t> wmi::WmiObject::get_property(std::wstring name) const
	{
        _variant_t var;
        
        if (!try_get_property(name, m_object, var))
        {
            return std::nullopt;
        }

        switch (var.vt)
        {
        case VT_BOOL:
            return value_t{ var.boolVal };

        case VT_I4:
        case VT_INT:
        case VT_UINT:
            return value_t{ static_cast<int32_t>(var.intVal) };

        case VT_BSTR:
            if (var.bstrVal)
                return value_t{ std::wstring{ var.bstrVal } };
            else
                return std::nullopt;

        default:
            return std::nullopt;
        }
	}
}
