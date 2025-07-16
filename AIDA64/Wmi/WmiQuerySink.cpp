#include "pch.h"
#include "WmiQuerySink.h"

namespace wmi
{
	std::vector<wmi::WmiObject> WmiQuerySink::Results() noexcept 
	{
		std::lock_guard<win32::critical_section> lock(m_cs);
		auto copy = std::move(m_results); 
		return copy;          
	}
	HRESULT STDMETHODCALLTYPE WmiQuerySink::Indicate(LONG lObjectCount, IWbemClassObject** apObjArray) noexcept
	{
		if (!apObjArray) return E_POINTER;

		std::lock_guard<win32::critical_section> lock(m_cs);

		m_results.reserve(m_results.size() + lObjectCount);
		
		for (LONG i = 0; i < lObjectCount; i++)
		{
			m_results.emplace_back(apObjArray[i]);
		}
		return WBEM_S_NO_ERROR;
	}
	HRESULT STDMETHODCALLTYPE WmiQuerySink::SetStatus(LONG lFlags, HRESULT hResult, BSTR strParam, IWbemClassObject* pObjParam) noexcept
	{
		return ::SetEvent(m_event.get()) ? WBEM_S_NO_ERROR : WBEM_E_FAILED;
	}
	winrt::Windows::Foundation::IAsyncAction WmiQuerySink::WaitAsync()
	{
		co_await winrt::resume_on_signal(m_event.get());
	}
}