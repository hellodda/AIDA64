#include "pch.h"
#include "ApplicationConfiguration.h"

namespace winrt::AIDA64::configuration
{
	ApplicationConfiguration& ApplicationConfiguration::Instance()
	{
		static ApplicationConfiguration instance;
		return instance;
	}

    winrt::Windows::Foundation::IAsyncOperation<hstring> ApplicationConfiguration::LoadDataAsync(hstring const& key) const 
    {
        try
        {
            co_await winrt::resume_background();

            auto localFolder = winrt::Windows::Storage::ApplicationData::Current().LocalFolder();
            auto file = co_await localFolder.GetFileAsync(m_configFileName);
            auto text = co_await winrt::Windows::Storage::FileIO::ReadTextAsync(file);

            winrt::Windows::Data::Json::JsonObject json = winrt::Windows::Data::Json::JsonObject::Parse(text);
            auto value = json.GetNamedString(key);

            co_return value;
        }
        catch (winrt::hresult_error const& e)
        {
            co_return e.message();
        }
        catch (std::exception const& e)
        {
            co_return to_hstring(e.what());
        }
    }
    winrt::Windows::Foundation::IAsyncAction ApplicationConfiguration::SaveDataAsync(hstring const& key, hstring const& value)
    {
        auto localFolder = winrt::Windows::Storage::ApplicationData::Current().LocalFolder();

        winrt::Windows::Data::Json::JsonObject json;

        try
        {
            auto file = co_await localFolder.GetFileAsync(m_configFileName);
            auto text = co_await winrt::Windows::Storage::FileIO::ReadTextAsync(file);
            json = winrt::Windows::Data::Json::JsonObject::Parse(text);
        }
        catch (winrt::hresult_error const& e)
        {
            json = winrt::Windows::Data::Json::JsonObject();
        }
        json.Insert(key, Windows::Data::Json::JsonValue::CreateStringValue(value));

        auto file = co_await localFolder.CreateFileAsync(m_configFileName, winrt::Windows::Storage::CreationCollisionOption::ReplaceExisting);
        co_await winrt::Windows::Storage::FileIO::WriteTextAsync(file, json.Stringify());
    }
}