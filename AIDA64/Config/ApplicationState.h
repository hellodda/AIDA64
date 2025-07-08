#pragma once

namespace winrt::AIDA64::configuration
{
	struct ApplicationState
	{
		static ApplicationState& Instance()
		{
			static ApplicationState instance;
			return instance;
		}
		
		Windows::Foundation::IAsyncAction ConfigureApplication();
		Windows::Foundation::IAsyncAction ConfigureApplication(std::function<Windows::Foundation::IAsyncAction(ApplicationState&)> schema);

		Microsoft::UI::Xaml::Window Window() const noexcept;
		void Window(Microsoft::UI::Xaml::Window const& value);

		bool EcoMode() const noexcept;
		void EcoMode(bool value);

		Microsoft::UI::Xaml::Media::SystemBackdrop Backdrop() const noexcept;
		void Backdrop(Microsoft::UI::Xaml::Media::SystemBackdrop const& value);

		void Test();

	private:
		Microsoft::UI::Xaml::Window m_window{ nullptr };
		Microsoft::UI::Xaml::Media::SystemBackdrop m_backdrop{ nullptr };

		winrt::Microsoft::UI::Composition::SystemBackdrops::MicaController m_micaController{ nullptr };
		winrt::Microsoft::UI::Composition::SystemBackdrops::SystemBackdropConfiguration m_backdropConfiguration{ nullptr };

		bool m_ecoEnabled;
	};
}