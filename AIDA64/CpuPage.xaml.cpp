#include "pch.h"
#include "CpuPage.xaml.h"
#if __has_include("CpuPage.g.cpp")
#include "CpuPage.g.cpp"
#endif

#include <Framework/ICpuService.h>
#include <Framework/CpuService.h>
#include <Framework/Utilities.h>
#include <iostream>
#include <memory>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::AIDA64::implementation
{
	CpuPage::CpuPage()
	{
		NavigationCacheMode(Microsoft::UI::Xaml::Navigation::NavigationCacheMode::Required);
    }
	void CpuPage::OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
	{
		if (auto param = e.Parameter().try_as<AIDA64::CpuPageViewModel>())
		{
			m_viewModel = param;
		}
	}

	winrt::CpuPageViewModel CpuPage::ViewModel()
	{
		return m_viewModel;
	}
	
}
