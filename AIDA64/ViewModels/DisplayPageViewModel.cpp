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
		IsLoading(true);

		auto model = co_await m_service->GetDisplayInformationAsync();

		IsLoading(false);

		if (!model) co_return;

		DisplayModel(model);

		co_return;
	}
	void DisplayPageViewModel::OnActivate()
	{
		if (!m_service || !m_logger) throw hresult_error(E_FAIL, L"null!");

		LoadDataAsync();
	}
}
