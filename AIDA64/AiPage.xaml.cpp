#include "pch.h"
#include "AiPage.xaml.h"
#if __has_include("AiPage.g.cpp")
#include "AiPage.g.cpp"
#endif

#include <Convertors/MessageAlignmentConverter.h>
#include <Convertors/VisibilityConverter.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::AIDA64::implementation
{
	AiPage::AiPage()
	{
		InitializeComponent();

		Resources().Insert(winrt::box_value(hstring{ L"MessageAlignmentConverter" }), winrt::make<Convertors::MessageAlignmentConverter>());
		Resources().Insert(winrt::box_value(hstring{ L"VisibilityConverter" }), winrt::make<Convertors::VisibilityConverter>());
	}

	void AiPage::OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
	{
		if (auto param = e.Parameter().try_as<AIDA64::AiPageViewModel>())
		{
			m_viewmodel = param;
		}
	}
	AIDA64::AiPageViewModel AiPage::ViewModel()
	{
		return m_viewmodel;
	}
}

void winrt::AIDA64::implementation::AiPage::Page_KeyDown(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::KeyRoutedEventArgs const& e)
{
	if (e.Key() == winrt::Windows::System::VirtualKey::Enter)
	{
		if (ViewModel().SendRequest().CanExecute(nullptr))
		{
			ViewModel().SendRequest().Execute(nullptr);
			RequestBox().Text(L"");
			RequestBox().PlaceholderText(L"");
		}
		e.Handled(true);
	}
}
