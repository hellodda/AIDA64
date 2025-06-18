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
	
		std::vector<com_ptr<IWbemClassObject>> Query(hstring query);
		std::future<std::vector<com_ptr<IWbemClassObject>>> QueryAsync(hstring query);

	private:

		com_ptr<IWbemServices> m_services{ nullptr };
	};
}
