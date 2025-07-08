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

		void Uri(Windows::Foundation::Uri const& uri);
		void Token(hstring const& token);
		void SystemConfiguration(hstring const& config);

		JsonObject BuildRequestJson(hstring const& systemConfig, hstring const& userRequest);
		hstring ParseChatContent(hstring const& jsonText);

	private:
		Windows::Foundation::Uri m_uri{ L"https://api.intelligence.io.solutions/api/v1/chat/completions" };
		hstring m_systemConfiguration{ L"You are a useful assistant AIDA64. AIDA64-WinUI3 applications your goal is to help the user with the computer." };
		hstring m_token{ L"io-v2-eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCJ9.eyJvd25lciI6IjcwZjA1OTI5LWY2NWYtNDRkMi05MTUxLWU3NjMxM2Y5NGRkYSIsImV4cCI6NDkwNTQ5ODk3Mn0.KPfbfz-7Zjiq7MiE4F0Srf2EwzowFQFYYuWZiJBLHLmAoxfAaVvdIYumk3OWdATrcgJTLUcM70GH4hqcqAeE8Q" };
		HttpClient m_client;
	};
}