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

	winrt::IVectorView<Point> CpuPageViewModel::UsagePoints() const noexcept
	{
		return m_cpuUsagePoints.GetView();
	}

	void CpuPageViewModel::UsagePoints(winrt::IVectorView<Point> const& value)
	{
		if (m_cpuUsagePoints != value)
		{
			for (auto var : value)
			{
				m_cpuUsagePoints.Append(var);
			}
			RaisePropertyChanged(L"UsagePoints");
		}
	}

	winrt::IAsyncAction CpuPageViewModel::LoadDataAsync()
	{
		if (!m_service) co_return;

		auto model = (co_await m_service->GetCpuInformationAsync()).GetAt(0);

		if (!model) co_return;

		CpuModel(model);
				

			winrt::IVector<winrt::Windows::Foundation::Point> points = single_threaded_vector<Point>();

		float width = 1000.0f;
		float height = 250.0f;
		int count = 100;
		float maxYValue = 250.0f;

		for (int i = 0; i < count; ++i)
		{
			float x = i * (width / (count - 1));
			float y = static_cast<float>(std::rand() % static_cast<int>(maxYValue));
			float yCoord = height - y;

			points.Append({ x, yCoord });
		}

		points.Append({ width, height });
		points.Append({ 0, height });
		

		UsagePoints(points.GetView());

		co_return;
	}
}
