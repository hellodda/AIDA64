#include "pch.h"
#include "AiClient.h"
#include <winrt/Windows.Web.Http.h>
#include <winrt/Windows.Data.Json.h>
#include <regex>

using namespace winrt;
using namespace Windows::Web::Http;
using namespace Windows::Data::Json;
using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Web::Http::Headers;

namespace winrt::AIDA64::Framework
{
    IAsyncOperation<hstring> AiClient::SendRequestAsync(hstring const& request)
    {
        try
        {
            Uri uri{ m_baseAddress + L"/Ai?message=" + Uri::EscapeComponent(request) };
            HttpRequestMessage req{ HttpMethod::Get(), uri };

            auto resp = co_await m_client.SendRequestAsync(req);
            resp.EnsureSuccessStatusCode();

            auto respText = co_await resp.Content().ReadAsStringAsync();

            co_return respText;
        }
        catch (hresult_error const& ex)
        {
            co_return ex.message();
        }
        catch (...)
        {
            co_return L"[Error] Unexpected failure";
        }
    }
}
