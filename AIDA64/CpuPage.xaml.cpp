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

IAsyncAction Load()
{
	co_await winrt::resume_background();

	std::shared_ptr<winrt::AIDA64::Framework::ICpuService> service = std::make_shared<winrt::AIDA64::Framework::CpuService>(get_mta_wmi_context());
	auto result = co_await service->GetAllProcessorsAsync();

	for (auto& info : result)
	{
		std::cout << info.LoadPercentage() << std::endl;
		MessageBoxW(NULL, info.Name().c_str(), info.Manufacturer().c_str(), MB_OK);
	}
	co_return;
}

namespace winrt::AIDA64::implementation
{
	CpuPage::CpuPage()
	{
		wait(Load);
		NavigationCacheMode(Microsoft::UI::Xaml::Navigation::NavigationCacheMode::Required);
    }

	
}
