#include "pch.h"
#include "ChatMessage.h"
#if __has_include("ChatMessage.g.cpp")
#include "ChatMessage.g.cpp"
#endif

namespace winrt::AIDA64::implementation
{
	hstring ChatMessage::Message() const noexcept
	{
		return m_message;
	}
	void ChatMessage::Message(hstring const& value)
	{
		if (m_message != value)
		{
			m_message = value;
		}
	}
	bool ChatMessage::IsSent() const noexcept
	{
		return m_isSent;
	}
	void ChatMessage::IsSent(bool value)
	{
		if (m_isSent != value)
		{
			m_isSent = value;
		}
	}
}
