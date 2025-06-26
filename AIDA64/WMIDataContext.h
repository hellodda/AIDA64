#pragma once
#include "IDataContext.h"

static constexpr const wchar_t* STANDART_NAMESPACE = L"ROOT\\CIMV2";

namespace winrt
{
	using namespace winrt::Windows::Foundation;
	using namespace winrt::Windows::Foundation::Collections;
}

namespace winrt::AIDA64::Framework
{
	struct WmiDataContext : IDataContext
	{
		WmiDataContext();
		~WmiDataContext();
	
		std::vector<com_ptr<IWbemClassObject>> Query(hstring const& query) override;
		IAsyncAction QueryAsync(hstring const& query, std::vector<com_ptr<IWbemClassObject>>& result) override;

		void ContextNameSpace(hstring const& namespace_);
		hstring ContextNameSpace() const noexcept;

	private:

		void initialize();

	private:		
		
		hstring m_namespace{ STANDART_NAMESPACE };
		com_ptr<IWbemServices> m_services{ nullptr };
	};
}
