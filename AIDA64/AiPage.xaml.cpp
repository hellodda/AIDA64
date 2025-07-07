#include "pch.h"
#include "AiPage.xaml.h"
#if __has_include("AiPage.g.cpp")
#include "AiPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::AIDA64::implementation
{
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
