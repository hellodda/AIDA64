#pragma once

namespace winrt
{
	using namespace winrt::Windows::Foundation;
	using namespace winrt::Windows::Foundation::Collections;
}


namespace winrt::AIDA64::Framework
{
	struct IDataContext
	{
		virtual std::vector<com_ptr<IWbemClassObject>> Query(hstring const& query) = 0;
		virtual IAsyncAction QueryAsync(hstring const& query, std::vector<com_ptr<IWbemClassObject>>& result) = 0;

	};
}