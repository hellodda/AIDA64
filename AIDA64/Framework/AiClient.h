#pragma once
#include <winrt/Windows.Networking.h>
#include <winrt/Windows.Web.Http.h>
#include <winrt/Windows.Data.Json.h>
#include "IAiClient.h"

using namespace winrt;
using namespace Windows::Web::Http;
using namespace Windows::Data::Json;

namespace winrt::AIDA64::Framework
{
	struct AiClient : IAiClient
	{
		Windows::Foundation::IAsyncOperation<hstring> SendRequestAsync(hstring const& request) override;
	private:
		hstring m_baseAddress = L"http://localhost:5091";
		HttpClient m_client;
	};
}