#pragma once
#include <variant>

namespace wmi
{
	using value_t = std::variant<std::wstring, int, uint32_t, bool>;

	struct WmiObject
	{
		WmiObject(winrt::com_ptr<IWbemClassObject> object) : m_object(std::move(object)) {}
		WmiObject(IWbemClassObject* object);

		std::optional<value_t> get_property(std::wstring name) const;

		
        template<typename T>
        std::optional<T> get_property(std::wstring const& name) const
        {
            auto opt = get_property(name);
            if (!opt) return std::nullopt;

            if (auto p = std::get_if<T>(&*opt))
                return *p;

            return std::nullopt;
        }


	private:

		winrt::com_ptr<IWbemClassObject> m_object;
	};
}