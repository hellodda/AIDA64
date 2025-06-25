#include "pch.h"
#include "DisplayPageViewModel.h"
#if __has_include("DisplayPageViewModel.g.cpp")
#include "DisplayPageViewModel.g.cpp"
#endif

namespace winrt::AIDA64::implementation
{
	void DisplayPageViewModel::Inject(std::shared_ptr<IDisplayService> service, std::shared_ptr<ILogger> logger)
	{
		m_service = std::move(service);
		m_logger = std::move(logger);
		LoadDataAsync();
	}

	winrt::DisplayModel DisplayPageViewModel::DisplayModel()
	{
		return m_display_model;
	}

	void DisplayPageViewModel::DisplayModel(winrt::DisplayModel const& value)
	{
		if (m_display_model != value)
		{
			m_display_model = value;
			RaisePropertyChanged(L"DisplayModel");
		}
	}
	winrt::IAsyncAction DisplayPageViewModel::LoadDataAsync()
	{
		if (!m_service) co_return;

		auto model = co_await m_service->GetDisplayInformationAsync();

		if (!model) co_return;

		DisplayModel(model);

		co_return;
	}
}
