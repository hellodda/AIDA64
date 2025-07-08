#pragma once

#include "ChatMessage.g.h"

namespace winrt::AIDA64::implementation
{
    struct ChatMessage : ChatMessageT<ChatMessage>
    {
        ChatMessage() = default;

        hstring Message() const noexcept;
        void Message(hstring const& value);

        bool IsSent() const noexcept;
        void IsSent(bool value);

    private:
        hstring m_message;
        bool m_isSent;
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct ChatMessage : ChatMessageT<ChatMessage, implementation::ChatMessage>
    {
    };
}
