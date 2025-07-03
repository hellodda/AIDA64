#pragma once
#include "IWmiDataContext.h"
#include "WmiObject.h"

static constexpr const wchar_t* STANDART_NAMESPACE = L"ROOT\\CIMV2";

namespace wmi
{
	struct WmiDataContext : IWmiDataContext
	{
		WmiDataContext();
		~WmiDataContext();
	
		std::vector<wmi::WmiObject> Query(_bstr_t const& query) override;
		async::task<std::vector<wmi::WmiObject>>QueryAsync(_bstr_t const& query) override;

		void ContextNamespace(_bstr_t const& namespace_);
		_bstr_t ContextNamespace() const noexcept;

	private:

		void initialize();

	private:		
		
		_bstr_t m_namespace{ STANDART_NAMESPACE };
		winrt::com_ptr<IWbemServices> m_services{ nullptr };
	};
}
