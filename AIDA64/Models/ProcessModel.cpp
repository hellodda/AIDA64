#include "pch.h"
#include "ProcessModel.h"
#if __has_include("ProcessModel.g.cpp")
#include "ProcessModel.g.cpp"
#endif

namespace winrt::AIDA64::implementation
{
    hstring ProcessModel::Name()
    {
        return m_name;
    }

    void ProcessModel::Name(hstring const& value)
    {
        if (m_name != value)
        {
            m_name = value;
        }
    }

    uint32_t ProcessModel::Id()
    {
        return m_id;
    }

    void ProcessModel::Id(uint32_t const& value)
    {
        if (m_id != value)
        {
            m_id = value;
        }
    }

    uint32_t ProcessModel::ThreadCount()
    {
        return m_threadCount;
    }

    void ProcessModel::ThreadCount(uint32_t const& value)
    {
        if (m_threadCount != value)
        {
            m_threadCount = value;
        }
    }
}
