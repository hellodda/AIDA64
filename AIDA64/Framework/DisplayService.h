#pragma once
#include "IDisplayService.h"

#include <Wmi/IWmiDataContext.h>
#include <Models/DisplayModel.h>

namespace winrt::AIDA64::Framework
{
    struct DisplayService : IDisplayService
    {
        DisplayService(std::shared_ptr<wmi::IWmiDataContext> context);

        Windows::Foundation::IAsyncOperation<AIDA64::DisplayModel>GetDisplayInformationAsync() override;

    private:
        std::shared_ptr<wmi::IWmiDataContext> m_context;
    };
}