#include "pch.h"
#include "AiPageViewModel.h"
#if __has_include("AiPageViewModel.g.cpp")
#include "AiPageViewModel.g.cpp"
#endif

namespace winrt::AIDA64::implementation
{
	void AiPageViewModel::Inject(std::shared_ptr<IAiClient> client)
	{
		m_client = std::move(client);
	}
	ICommand AiPageViewModel::SendRequest()
	{
		if (!m_sendRequestCommand)
		{
			m_sendRequestCommand = winrt::make<Helpers::RelayCommand>([this]() -> IAsyncAction {

				AIDA64::ChatMessage ai_message;
				AIDA64::ChatMessage my_message;

				my_message.Message(m_requestMessage);
				my_message.IsSent(true);

				m_messages.Append(my_message);

				auto response = co_await m_client->SendRequestAsync(m_requestMessage);
				
				ai_message.Message(response);
				ai_message.IsSent(false);
				
				m_messages.Append(ai_message);
			});
		}
		return m_sendRequestCommand;
	}
	hstring AiPageViewModel::ResponseMessage() const noexcept
	{
		return m_responseMessage;
	}
	void AiPageViewModel::ResponseMessage(hstring const& value)
	{
		if (m_responseMessage != value)
		{
			m_responseMessage = value;
			RaisePropertyChanged(L"ResponseMessage");
		}
	}
	hstring AiPageViewModel::RequestMessage() const noexcept
	{
		return m_requestMessage;
	}
	void AiPageViewModel::RequestMessage(hstring const& value)
	{
		if (m_requestMessage != value)
		{
			m_requestMessage = value;
			RaisePropertyChanged(L"RequestMessage");
		}
	}
	Windows::Foundation::Collections::IObservableVector<AIDA64::ChatMessage> AiPageViewModel::Messages() const noexcept
	{
		return m_messages;
	}
	void AiPageViewModel::Messages(Windows::Foundation::Collections::IObservableVector<AIDA64::ChatMessage> const& value)
	{
		if (m_messages != value)
		{
			m_messages = value;
			RaisePropertyChanged(L"Messages");
		}
	}
}
