#include "pch.h"
#include "WmiQuerySink.h"

namespace wmi
{
	HRESULT STDMETHODCALLTYPE WmiQuerySink::Indicate(LONG lObjectCount, IWbemClassObject** apObjArray) noexcept
	{
		for (LONG i = 0; i < lObjectCount; i++)
		{
			winrt::com_ptr<IWbemClassObject> ptr;
			apObjArray[i]->AddRef();
			results.emplace_back(apObjArray[i]);
		}
		return WBEM_S_NO_ERROR;
	}
	HRESULT STDMETHODCALLTYPE WmiQuerySink::SetStatus(LONG lFlags, HRESULT hResult, BSTR strParam, IWbemClassObject* pObjParam) noexcept
	{
		::SetEvent(event.get());
		return WBEM_S_NO_ERROR;
	}
	winrt::Windows::Foundation::IAsyncAction WmiQuerySink::wait_async()
	{
		co_await winrt::resume_on_signal(event.get());
	}
}