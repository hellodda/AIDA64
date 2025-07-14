#pragma once

#include "AiPageViewModel.g.h"
#include <Framework/IAiClient.h>

#include <Helpers/BindableBase.h>
#include <Helpers/RelayCommand.h>
#include <Helpers/ViewModelBase.h>

#include <Models/ChatMessage.h>

using namespace winrt::AIDA64::Framework;

namespace winrt::AIDA64::implementation
{
    struct AiPageViewModel : AiPageViewModelT<AiPageViewModel, Helpers::ViewModelBase>
    {
        AiPageViewModel() = default;

        void Inject(std::shared_ptr<IAiClient> client);

        ICommand SendRequest();

        hstring ResponseMessage() const noexcept;
        void ResponseMessage(hstring const& value);

        hstring RequestMessage() const noexcept;
        void RequestMessage(hstring const& value);

        Windows::Foundation::Collections::IObservableVector<AIDA64::ChatMessage> Messages() const noexcept;
        void Messages(Windows::Foundation::Collections::IObservableVector<AIDA64::ChatMessage> const& value);

        void OnActivate() override;

    private:
        ICommand m_sendRequestCommand;
        hstring m_requestMessage;
        hstring m_responseMessage;
        Windows::Foundation::Collections::IObservableVector<AIDA64::ChatMessage> m_messages = single_threaded_observable_vector<AIDA64::ChatMessage>();
        std::shared_ptr<IAiClient> m_client;
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct AiPageViewModel : AiPageViewModelT<AiPageViewModel, implementation::AiPageViewModel>
    {
    };
}
