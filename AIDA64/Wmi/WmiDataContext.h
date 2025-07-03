#pragma once
#include "IWmiDataContext.h"
#include "WmiObject.h"


static constexpr const wchar_t* STANDART_NAMESPACE = L"ROOT\\CIMV2";

namespace winrt
{
	using namespace winrt::Windows::Foundation;
	using namespace winrt::Windows::Foundation::Collections;
}

namespace winrt::AIDA64::Framework
{
	struct WmiDataContext : IWmiDataContext
	{
		WmiDataContext();
		~WmiDataContext();
	
		std::vector<wmi::WmiObject> Query(hstring const& query) override;
		async::task<std::vector<wmi::WmiObject>>QueryAsync(hstring const& query) override;

		void ContextNamespace(hstring const& namespace_);
		hstring ContextNamespace() const noexcept;

	private:

		void initialize();

	private:		
		
		hstring m_namespace{ STANDART_NAMESPACE };
		com_ptr<IWbemServices> m_services{ nullptr };
	};
}
