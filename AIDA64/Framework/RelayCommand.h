#pragma once

namespace winrt
{
	using namespace Windows::Foundation;
	using namespace Microsoft::UI::Xaml::Input;
}

namespace winrt::AIDA64::Framework
{
	struct RelayCommand : winrt::implements<RelayCommand, winrt::ICommand>
	{
        RelayCommand(std::function<IAsyncAction()> execute, std::function<bool()> canExecute = nullptr)
            : m_execute(std::move(execute)), m_canExecute(std::move(canExecute)) {}

        winrt::event<winrt::EventHandler<winrt::IInspectable>> m_canExecuteChanged;

        void Execute(winrt::IInspectable const&) const;

        bool CanExecute(winrt::IInspectable const&) const;

        winrt::event_token CanExecuteChanged(winrt::EventHandler<winrt::IInspectable> const& handler);

        void CanExecuteChanged(winrt::event_token const& token) noexcept;

        void RaiseCanExecuteChanged();


    private:
        std::function<IAsyncAction()> m_execute;
        std::function<bool()> m_canExecute;
	};
}

