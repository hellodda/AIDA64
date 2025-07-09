#pragma once
#include <optional>
#include <variant>
#include <string>

namespace wmi
{
	using property_value_t = std::variant<std::wstring, float, double, int64_t, int32_t, int16_t, int8_t, uint64_t, uint32_t, uint16_t, uint8_t, bool>;

	struct IWmiObject
	{
		virtual ~IWmiObject() = default;

        virtual std::optional<property_value_t> get_property(std::wstring name) const = 0;

        template<typename T>
        std::optional<T> get_property(std::wstring const& name) const
        {
            auto opt = get_property(name);

            if (!opt) return std::nullopt;

            if (auto p = std::get_if<T>(&*opt))
                return *p;

            return std::nullopt;
        }
	};
}