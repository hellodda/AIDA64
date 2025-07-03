#pragma once
#include "IDisplayService.h"

#include <Wmi/IWmiDataContext.h>
#include <Models/DisplayModel.h>

namespace winrt::AIDA64::Framework
{
    struct DisplayService : IDisplayService
    {
        DisplayService(std::shared_ptr<IWmiDataContext> context);

        Windows::Foundation::IAsyncOperation<AIDA64::DisplayModel>GetDisplayInformationAsync() override;

    private:
        std::shared_ptr<IWmiDataContext> m_context;
    };
}