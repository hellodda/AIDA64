#include "pch.h"
#include "CpuPageViewModel.h"
#if __has_include("CpuPageViewModel.g.cpp")
#include "CpuPageViewModel.g.cpp"
#endif

namespace winrt::AIDA64::implementation
{
	CpuPageViewModel::CpuPageViewModel()
	{

	}

	void CpuPageViewModel::Inject(std::shared_ptr<ICpuService> service, std::shared_ptr<ILogger> logger)
	{
		m_service = std::move(service);
		m_logger = std::move(logger);
		LoadDataAsync();
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
	winrt::IAsyncAction CpuPageViewModel::LoadDataAsync()
	{
		if (!m_service) co_return;

		auto model = (co_await m_service->GetAllCpusAsync()).GetAt(0);

		if (!model) co_return;

		CpuModel(model);

		co_return;
	}
}
