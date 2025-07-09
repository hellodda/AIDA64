#include "pch.h"
#include "MemoryPageViewModel.h"
#if __has_include("MemoryPageViewModel.g.cpp")
#include "MemoryPageViewModel.g.cpp"
#endif

namespace winrt::AIDA64::implementation
{
	void MemoryPageViewModel::Inject(std::shared_ptr<IMemoryService> service)
	{
		m_service = std::move(service);
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

	void MemoryPageViewModel::Activate()
	{
		LoadDataAsync();
	}

	IAsyncAction MemoryPageViewModel::LoadDataAsync()
	{
		if (!m_service) throw hresult_error(E_FAIL, L"Service is Null!");

		auto model = co_await m_service->GetMemoryInformationAsync();

		MemoryModel(model);
	}
}
