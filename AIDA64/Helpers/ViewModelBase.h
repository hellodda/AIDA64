#pragma once
#include "BindableBase.h"

namespace winrt::AIDA64::Helpers
{
	struct ViewModelBase : winrt::implements<ViewModelBase, BindableBase>
	{
		bool IsLoading() const noexcept;
		void IsLoading(bool value);

		virtual void OnActivate();
		void Activate();

		virtual void OnSuspend();
		void Suspend();

	private:
		bool m_isLoading{ false };
		bool m_isActivated{ false };
	};
}