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
		~WmiDataContext() = default;
	
		std::vector<com_ptr<IWbemClassObject>> Query(hstring const& query);
		std::future<std::vector<com_ptr<IWbemClassObject>>> QueryAsync(hstring const& query);

		void ContextNameSpace(hstring const& namespace_);
		hstring ContextNameSpace() const noexcept;

	private:

		IAsyncAction InitializeAsync();

	private:

		hstring m_usingNameSpace{ L"ROOT\\CIMV2" };
		com_ptr<IWbemServices> m_services{ nullptr };
	};
}
