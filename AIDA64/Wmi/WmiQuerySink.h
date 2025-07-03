#pragma once
#include "WmiObject.h"

namespace wmi
{
	struct WmiQuerySink : winrt::implements<WmiQuerySink, IWbemObjectSink>
	{
		std::vector<wmi::WmiObject> results;

		winrt::handle event{ ::CreateEventW(NULL, TRUE, FALSE, NULL) };

		HRESULT STDMETHODCALLTYPE Indicate(LONG lObjectCount, IWbemClassObject** apObjArray) noexcept override;

		HRESULT STDMETHODCALLTYPE SetStatus([[maybe_unused]] LONG lFlags, [[maybe_unused]] HRESULT hResult, [[maybe_unused]] BSTR strParam, [[maybe_unused]] IWbemClassObject* pObjParam) noexcept override;

		winrt::Windows::Foundation::IAsyncAction wait_async();
	};
}
