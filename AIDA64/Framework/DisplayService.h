#pragma once
#include "IDisplayService.h"
#include <WMIDataContext.h>

namespace winrt::AIDA64::Framework
{
	struct DisplayService : IDisplayService
	{
		DisplayService(std::shared_ptr<WmiDataContext> context);

		IAsyncOperation<DisplayModel> GetDisplayInformationAsync() override;

	private:

		std::shared_ptr<WmiDataContext> m_context;
	};
}

