#include "pch.h"
#include "DisplayPage.xaml.h"
#if __has_include("DisplayPage.g.cpp")
#include "DisplayPage.g.cpp"
#endif

#include <Convertors/ReverseVisibilityConverter.h>
#include <Convertors/VisibilityConverter.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::AIDA64::implementation
{
	DisplayPage::DisplayPage()
	{
		Resources().Insert(box_value(L"ReverseVisibilityConverter"), make<Convertors::ReverseVisibilityConverter>());
		Resources().Insert(box_value(L"VisibilityConverter"), make<Convertors::VisibilityConverter>());
	}

	winrt::DisplayPageViewModel DisplayPage::ViewModel()
	{
		return m_viewmodel;
	}

	void DisplayPage::OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
	{
		if (auto param = e.Parameter().try_as<AIDA64::DisplayPageViewModel>())
		{
			m_viewmodel = param;
			m_viewmodel.Activate();
		}
	}
}
