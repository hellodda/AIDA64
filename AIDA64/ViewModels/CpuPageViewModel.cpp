#include "pch.h"
#include "CpuPageViewModel.h"
#if __has_include("CpuPageViewModel.g.cpp")
#include "CpuPageViewModel.g.cpp"
#endif

#include <Framework/Utilities.h>

namespace winrt::AIDA64::implementation
{
	void CpuPageViewModel::Inject(std::shared_ptr<ICpuService> service, std::shared_ptr<ILogger> logger)
	{
		m_service = std::move(service);
		m_logger = std::move(logger);

		LoadData();
	}

	winrt::CpuModel CpuPageViewModel::CpuModel()
	{
		return m_cpu_model;
	}

	void CpuPageViewModel::CpuModel(winrt::CpuModel const& value)
	{
		if (m_cpu_model != value)
		{
			m_cpu_model = value;
			RaisePropertyChanged(L"CpuModel");
		}
	}
	winrt::IAsyncAction CpuPageViewModel::LoadData()
	{
		while (true)
		{
			auto model = (co_await m_service->GetAllProcessorsAsync()).GetAt(0);
			CpuModel(model);
		}
		

		co_return;
	}
}
