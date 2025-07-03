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
		for (LONG i = 0; i < lObjectCount; i++)
		{
			winrt::com_ptr<IWbemClassObject> ptr;
			apObjArray[i]->AddRef();
			m_results.emplace_back(apObjArray[i]);
		}
		return WBEM_S_NO_ERROR;
	}
	HRESULT STDMETHODCALLTYPE WmiQuerySink::SetStatus(LONG lFlags, HRESULT hResult, BSTR strParam, IWbemClassObject* pObjParam) noexcept
	{
		::SetEvent(m_event.get());
		return WBEM_S_NO_ERROR;
	}
	winrt::Windows::Foundation::IAsyncAction WmiQuerySink::wait_async()
	{
		co_await winrt::resume_on_signal(m_event.get());
	}
}