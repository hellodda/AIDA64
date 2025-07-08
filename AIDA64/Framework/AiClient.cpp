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
    JsonObject AiClient::BuildRequestJson(hstring const& systemConfig, hstring const& userRequest) {
        JsonObject body;
        body.Insert(L"model", JsonValue::CreateStringValue(L"meta-llama/Llama-4-Maverick-17B-128E-Instruct-FP8"));

        JsonArray messages;

        auto make_message = [&](std::wstring role, hstring content) {
            JsonObject obj;
            obj.Insert(L"role", JsonValue::CreateStringValue(role));
            obj.Insert(L"content", JsonValue::CreateStringValue(content));
            return obj;
        };

        messages.Append(make_message(L"system", systemConfig));
        messages.Append(make_message(L"user", userRequest));

        body.Insert(L"messages", messages);

      

        body.Insert(L"temperature", JsonValue::CreateNumberValue(0.0));
        body.Insert(L"stream", JsonValue::CreateBooleanValue(false));
        body.Insert(L"max_completion_tokens", JsonValue::CreateNumberValue(1000));
        return body;
    }

    hstring AiClient::ParseChatContent(hstring const& jsonText)
    {
        auto root = JsonObject::Parse(jsonText);
        auto choices = root.GetNamedArray(L"choices");
        if (choices.Size() == 0) {
            throw hresult_error(E_FAIL, L"No choices in response");
        }
        auto first = choices.GetObjectAt(0).GetNamedObject(L"message");
        auto content = first.GetNamedString(L"content");
        return content;
    }

    IAsyncOperation<hstring> AiClient::SendRequestAsync(hstring const& request)
    {
        try
        {
            HttpRequestMessage req{ HttpMethod::Post(), m_uri };
            req.Headers().Insert(L"Authorization", L"Bearer " + m_token);

            auto body = BuildRequestJson(m_systemConfiguration, request);
            req.Content(HttpStringContent{
                body.Stringify(),
                Windows::Storage::Streams::UnicodeEncoding::Utf8,
                L"application/json"
            });

            auto resp = co_await m_client.SendRequestAsync(req);
            resp.EnsureSuccessStatusCode();

            auto respText = co_await resp.Content().ReadAsStringAsync();

            co_return ParseChatContent(respText);
        }
        catch (hresult_error const& ex)
        {
            co_return L"[Error] " + ex.message();
        }
        catch (...)
        {
            co_return L"[Error] Unexpected failure";
        }
    }

    void AiClient::Uri(Windows::Foundation::Uri const& uri)
    {
        m_uri = uri;
    }
    void AiClient::Token(hstring const& token)
    {
        m_token = token;
    }
    void AiClient::SystemConfiguration(hstring const& cfg)
    {
        m_systemConfiguration = cfg;
    }
}
