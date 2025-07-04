#pragma once
#include "WmiObject.h"
#include <Win32Helpers/critical_section.h>

namespace wmi
{
	struct WmiQuerySink : winrt::implements<WmiQuerySink, IWbemObjectSink>
	{
		std::vector<wmi::WmiObject> Results() noexcept;

		HRESULT STDMETHODCALLTYPE Indicate(LONG lObjectCount, IWbemClassObject** apObjArray) noexcept override;

		HRESULT STDMETHODCALLTYPE SetStatus([[maybe_unused]] LONG lFlags, [[maybe_unused]] HRESULT hResult, [[maybe_unused]] BSTR strParam, [[maybe_unused]] IWbemClassObject* pObjParam) noexcept override;

		winrt::Windows::Foundation::IAsyncAction WaitAsync();

	private:
		win32::critical_section m_cs;
		winrt::handle m_event{ ::CreateEventW(NULL, TRUE, FALSE, NULL) };
		std::vector<wmi::WmiObject> m_results;
	};
}
