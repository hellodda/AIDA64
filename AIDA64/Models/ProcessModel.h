#pragma once

#include "ProcessModel.g.h"

namespace winrt::AIDA64::implementation
{
    struct ProcessModel : ProcessModelT<ProcessModel>
    {
        ProcessModel() = default;

        hstring Name();
        void Name(hstring const& value);

        uint32_t Id();
        void Id(uint32_t const& value);

        uint32_t ThreadCount();
        void ThreadCount(uint32_t const& value);

    private:

        hstring m_name{};
        uint32_t m_id{ 0 };
        uint32_t m_threadCount{ 0 };
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct ProcessModel : ProcessModelT<ProcessModel, implementation::ProcessModel>
    {
    };
}
