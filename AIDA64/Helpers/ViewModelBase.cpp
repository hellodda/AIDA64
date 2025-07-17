#include "pch.h"
#include "ViewModelBase.h"

namespace winrt::AIDA64::Helpers
{
	bool ViewModelBase::IsLoading() const noexcept
	{
		return m_isLoading;
	}
	void ViewModelBase::IsLoading(bool value)
	{
		if (m_isLoading != value)
		{
			m_isLoading = value;
			RaisePropertyChanged(L"IsLoading");
		}
	}
	void ViewModelBase::OnActivate()
	{

	}
	void ViewModelBase::OnSuspend()
	{

	}
	void ViewModelBase::Activate()
	{
		if (!m_isActivated)
		{
			OnActivate();
			m_isActivated = true;
		}
	}
	void ViewModelBase::Suspend()
	{
		if (m_isActivated)
		{
			OnSuspend();
			m_isActivated = false;
		}
	}
}