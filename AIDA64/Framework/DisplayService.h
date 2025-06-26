#pragma once
#include "IDisplayService.h"
#include <WMIDataContext.h>

namespace winrt::AIDA64::Framework
{
	struct DisplayService : IDisplayService
	{
		DisplayService(std::shared_ptr<IDataContext> context);

		IAsyncOperation<DisplayModel> GetDisplayInformationAsync() override;

	private:

		std::shared_ptr<IDataContext> m_context;
	};
}

