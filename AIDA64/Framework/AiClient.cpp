#include "pch.h"
#include "AiClient.h"
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Web.Http.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.Data.Json.h>

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Web::Http;
using namespace Windows::Storage::Streams;
using namespace Windows::Data::Json;

namespace winrt::AIDA64::Framework
{
    IAsyncOperation<hstring> AiClient::SendRequestAsync(hstring const& request)
    {
        HttpRequestMessage request_message{ HttpMethod::Post(), m_uri };

        request_message.Headers().Insert(L"Authorization", L"Bearer " + m_token);

        JsonObject body;
        body.Insert(L"model", JsonValue::CreateStringValue(L"deepseek-ai/DeepSeek-R1-0528"));

        JsonArray messages;

        JsonObject systemMessage;
        systemMessage.Insert(L"role", JsonValue::CreateStringValue(L"system"));
        systemMessage.Insert(L"content", JsonValue::CreateStringValue(L"You are a helpful assistant. Always respond only with your final answer enclosed inside <speak> and </speak> tags. Do not include any internal reasoning or other tags."));

        JsonObject userMessage;
        userMessage.Insert(L"role", JsonValue::CreateStringValue(L"user"));
        userMessage.Insert(L"content", JsonValue::CreateStringValue(request));

        messages.Append(systemMessage);
        messages.Append(userMessage);

        body.Insert(L"messages", messages);
        body.Insert(L"temperature", JsonValue::CreateNumberValue(0));
        body.Insert(L"stream", JsonValue::CreateBooleanValue(false));
        body.Insert(L"max_completion_tokens", JsonValue::CreateNumberValue(500));

        request_message.Content(HttpStringContent(body.Stringify(), UnicodeEncoding::Utf8, L"application/json"));

        auto response = co_await m_client.SendRequestAsync(request_message);
        auto response_buffer = co_await response.Content().ReadAsBufferAsync();

        DataReader reader = DataReader::FromBuffer(response_buffer);
        reader.UnicodeEncoding(UnicodeEncoding::Utf8);
        hstring response_body = reader.ReadString(reader.UnconsumedBufferLength());

        auto jsonResponse = Windows::Data::Json::JsonObject::Parse(response_body);

        Windows::Data::Json::JsonArray choices = jsonResponse.GetNamedArray(L"choices");

        if (choices.Size() > 0)
        {
            Windows::Data::Json::JsonObject firstChoice = choices.GetObjectAt(0);
            Windows::Data::Json::JsonObject message = firstChoice.GetNamedObject(L"message");
            hstring content = message.GetNamedString(L"content");
            std::wstring s = content.c_str();

            const std::wstring speakOpen = L"<speak>";
            const std::wstring speakClose = L"</speak>";

            size_t start = s.find(speakOpen);
            size_t end = s.find(speakClose);

            if (start != std::wstring::npos && end != std::wstring::npos && end > start)
            {
                s = s.substr(start + speakOpen.length(), end - (start + speakOpen.length()));
                co_return hstring{ s };
            }
            else
            {
                co_return L"Ответ не найден.";
            }
        }
        else
        {
            co_return L"No response content found.";
        }

    }

    void AiClient::Uri(Windows::Foundation::Uri uri)
    {
        m_uri = uri;
    }

    void AiClient::Token(hstring token)
    {
        m_token = token;
    }
}
