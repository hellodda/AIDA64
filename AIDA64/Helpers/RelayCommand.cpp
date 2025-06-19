#include "pch.h"
#include "RelayCommand.h"

namespace winrt::AIDA64::Helpers
{
	void RelayCommand::Execute(winrt::IInspectable const&) const
	{
		if (m_execute)
		{
			m_execute();
		}
	}
	bool RelayCommand::CanExecute(winrt::IInspectable const&) const
	{
		return m_canExecute ? m_canExecute() : true;
	}
	winrt::event_token RelayCommand::CanExecuteChanged(winrt::EventHandler<winrt::IInspectable> const& handler)
	{
		return m_canExecuteChanged.add(handler);
	}
	void RelayCommand::CanExecuteChanged(winrt::event_token const& token) noexcept
	{
		m_canExecuteChanged.remove(token);
	}
	void RelayCommand::RaiseCanExecuteChanged()
	{
		m_canExecuteChanged(nullptr, nullptr);
	}
}