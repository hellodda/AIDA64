#pragma once

namespace winrt
{
	using namespace winrt::Windows::Foundation;
	using namespace winrt::Windows::Foundation::Collections;
}

namespace winrt::AIDA64::Framework
{
	struct WmiDataContext
	{
		WmiDataContext();
		~WmiDataContext();
	
		std::vector<com_ptr<IWbemClassObject>> Query(hstring const& query);
		IAsyncAction WmiDataContext::QueryAsync(hstring const& query, std::vector<com_ptr<IWbemClassObject>>& result);

		void ContextNameSpace(hstring const& namespace_);
		hstring ContextNameSpace() const noexcept;

	private:

		void initialize();

	private:		
		
		hstring m_namespace{ L"ROOT\\CIMV2" };
		com_ptr<IWbemServices> m_services{ nullptr };
	};
}
