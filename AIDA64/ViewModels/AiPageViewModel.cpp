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

				auto response = co_await m_client->SendRequestAsync(m_requestMessage);
				ResponseMessage(response);
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
}
