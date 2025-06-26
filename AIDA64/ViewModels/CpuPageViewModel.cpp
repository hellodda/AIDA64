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

	winrt::ICommand CpuPageViewModel::TESTA()
	{
		if (!this->TEST)
		{
			TEST = winrt::make<RelayCommand>([this]() -> IAsyncAction {

				for (int i = 0; i < 1000; i++)
				{
					co_await LoadDataAsync();
				}


				co_return;
			});
		}
		return TEST;
	}

	winrt::IObservableVector<double> CpuPageViewModel::Values() const noexcept
	{
		return m_values;
	}

	winrt::IAsyncAction CpuPageViewModel::LoadDataAsync()
	{
		if (!m_service) co_return;

		auto model = (co_await m_service->GetCpuInformationAsync()).GetAt(0);

		if (!model) co_return;

		CpuModel(model);

		m_values.Append(model.LoadPercentage());

		RaisePropertyChanged(L"Values");

		co_return;
	}
}
