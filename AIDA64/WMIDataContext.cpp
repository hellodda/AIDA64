#include "pch.h"
#include "WMIDataContext.h"

#include <Framework/Utilities.h>

namespace winrt::AIDA64::Framework
{
	WmiDataContext::WmiDataContext()
	{
		InitializeAsync();
	}

	IAsyncAction WmiDataContext::InitializeAsync()
	{
		co_await winrt::resume_background();

		winrt::com_ptr<IWbemLocator> locator;
		winrt::check_hresult(CoCreateInstance(
			CLSID_WbemLocator,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_PPV_ARGS(locator.put())
		));

		winrt::check_hresult(locator->ConnectServer(
			BSTR(L"ROOT\\CIMV2"),
			NULL,
			NULL,
			0,
			NULL,
			0,
			0,
			m_services.put()
		));

		winrt::check_hresult(CoSetProxyBlanket(
			m_services.get(),
			RPC_C_AUTHN_WINNT,
			RPC_C_AUTHZ_NONE,
			NULL,
			RPC_C_AUTHN_LEVEL_CALL,
			RPC_C_IMP_LEVEL_IMPERSONATE,
			NULL,
			EOAC_NONE
		));

		co_return;
	}

	std::vector<com_ptr<IWbemClassObject>> WmiDataContext::Query(hstring query)
	{
		winrt::com_ptr<IEnumWbemClassObject> enumerator{ nullptr };

		winrt::check_hresult(m_services->ExecQuery(
			BSTR(L"WQL"),
			BSTR(query.c_str()),
			WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
			NULL,
			enumerator.put()
		));

		std::vector<com_ptr<IWbemClassObject>> objects;
		ULONG uReturn{ 0 };

		while (enumerator)
		{
			com_ptr<IWbemClassObject> object{ nullptr };

			enumerator->Next(WBEM_INFINITE, 1, object.put(), &uReturn);

			if (uReturn == 0) break;

			objects.push_back(object);
		}
		return objects;
	}

	std::future<std::vector<com_ptr<IWbemClassObject>>> WmiDataContext::QueryAsync(hstring query)
	{
		return std::async(std::launch::async, [this, query] {
			apartment_guard<apartment_type::multi_threaded> mta_context;
			return Query(query);
		});
	}

	void WmiDataContext::ContextNameSpace(hstring const& nameSpace)
	{
		if (m_usingNameSpace != nameSpace)
		{
			m_usingNameSpace = nameSpace;
		}
	}

	hstring WmiDataContext::ContextNameSpace() const noexcept
	{
		return m_usingNameSpace;
	}
	
}
