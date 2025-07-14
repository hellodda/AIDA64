#include "pch.h"
#include "MemoryPage.xaml.h"
#if __has_include("MemoryPage.g.cpp")
#include "MemoryPage.g.cpp"
#endif

#include <Convertors/ReverseVisibilityConverter.h>
#include <Convertors/VisibilityConverter.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;


namespace winrt::AIDA64::implementation
{
	MemoryPage::MemoryPage()
	{
		Resources().Insert(box_value(L"VisibilityConverter"), make<Convertors::VisibilityConverter>());
		Resources().Insert(box_value(L"ReverseVisibilityConverter"), make<Convertors::ReverseVisibilityConverter>());
	}

	void MemoryPage::OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
	{
		if (auto param = e.Parameter().try_as<AIDA64::MemoryPageViewModel>())
		{
			m_viewmodel = param;
			m_viewmodel.Activate();
		}
	}
	AIDA64::MemoryPageViewModel MemoryPage::ViewModel() const noexcept
	{
		return m_viewmodel;
	}
}
