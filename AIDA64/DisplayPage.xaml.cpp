#include "pch.h"
#include "DisplayPage.xaml.h"
#if __has_include("DisplayPage.g.cpp")
#include "DisplayPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::AIDA64::implementation
{
	winrt::DisplayPageViewModel DisplayPage::ViewModel()
	{
		return m_viewmodel;
	}

	void DisplayPage::OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
	{
		if (auto param = e.Parameter().try_as<AIDA64::DisplayPageViewModel>())
		{
			m_viewmodel = param;
		}
	}
}
