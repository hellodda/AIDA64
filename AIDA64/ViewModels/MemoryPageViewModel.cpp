#include "pch.h"
#include "MemoryPageViewModel.h"
#if __has_include("MemoryPageViewModel.g.cpp")
#include "MemoryPageViewModel.g.cpp"
#endif

namespace winrt::AIDA64::implementation
{
	void MemoryPageViewModel::Inject(std::shared_ptr<IMemoryService> service, std::shared_ptr<ILogger> logger)
	{
		m_service = std::move(service);
		m_logger = std::move(logger);
	}

	AIDA64::MemoryModel MemoryPageViewModel::MemoryModel() const noexcept
	{
		return m_memory_model;
	}

	void MemoryPageViewModel::MemoryModel(AIDA64::MemoryModel const& value)
	{
		if (m_memory_model != value)
		{
			m_memory_model = value;
			RaisePropertyChanged(L"MemoryModel");
		}
	}

	void MemoryPageViewModel::OnActivate()
	{
		if (!m_service || !m_logger) throw hresult_error(E_FAIL, L"null!");

		LoadDataAsync();
	}

	IAsyncAction MemoryPageViewModel::LoadDataAsync()
	{
		IsLoading(true);

		auto model = co_await m_service->GetMemoryInformationAsync();

		IsLoading(false);

		MemoryModel(model);
	}
}
