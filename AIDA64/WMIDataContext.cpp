#include "pch.h"
#include "WMIDataContext.h"

#include <Framework/Utilities.h>


namespace winrt::AIDA64::Framework
{
	WmiDataContext::WmiDataContext()
	{
		initialize();
	}

	WmiDataContext::~WmiDataContext()
	{
		winrt::uninit_apartment();
	}

	void WmiDataContext::initialize()
	{
		winrt::com_ptr<IWbemLocator> locator;
		winrt::check_hresult(CoCreateInstance(
			CLSID_WbemLocator,
			NULL,
			CLSCTX_INPROC_SERVER,
			__uuidof(IWbemLocator),
			locator.put_void()
		));

		winrt::check_hresult(locator->ConnectServer(
			BSTR(m_namespace.c_str()),
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
	}

	std::vector<wmi::WmiObject> WmiDataContext::Query(hstring const& query)
	{
		winrt::com_ptr<IEnumWbemClassObject> enumerator{ nullptr };

		winrt::check_hresult(m_services->ExecQuery(
			BSTR(L"WQL"),
			BSTR(query.c_str()),
			WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
			NULL,
			enumerator.put()
		));

		std::vector<wmi::WmiObject> objects;
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

	async::task<std::vector<wmi::WmiObject>> WmiDataContext::QueryAsync(hstring const& query)
	{
		co_await winrt::resume_background();

		auto result = Query(query);

		co_return result;
	}

	void WmiDataContext::ContextNameSpace(hstring const& namespace_)
	{
		if (m_namespace != namespace_)
		{
			m_namespace = namespace_;
		}
	}

	hstring WmiDataContext::ContextNameSpace() const noexcept
	{
		return m_namespace;
	}
	
}
