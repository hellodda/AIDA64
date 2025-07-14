#include "pch.h"
#include "CpuPageViewModel.h"
#if __has_include("CpuPageViewModel.g.cpp")
#include "CpuPageViewModel.g.cpp"
#endif

#include <Framework/Utilities.h>

namespace winrt::AIDA64::implementation
{
	CpuPageViewModel::CpuPageViewModel()
	{
	
	}

	void CpuPageViewModel::Inject(std::shared_ptr<ICpuService> service, std::shared_ptr<ILogger> logger)
	{
		m_service = std::move(service);
		m_logger = std::move(logger);
	}

	winrt::CpuModel CpuPageViewModel::CpuModel() const noexcept
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

	void CpuPageViewModel::Values(winrt::IObservableVector<double> const& value)
	{
		if (m_values != value)
		{
			m_values = value;
			RaisePropertyChanged(L"Values");
		}
	}
	winrt::IObservableVector<double> CpuPageViewModel::Values() const noexcept
	{
		return m_values;
	}

	void CpuPageViewModel::OnActivate()
	{
		IsLoading(true);

		get_instance<DispatcherTaskScheduler>().AddTask([&]() -> IAsyncAction {

			auto result = (co_await m_service->GetCpuInformationAsync()).GetAt(0);

			IsLoading(false);

			CpuModel(result);

			m_values.Append(static_cast<double>(result.LoadPercentage()));
			RaisePropertyChanged(L"Values");
		});
	}
}
