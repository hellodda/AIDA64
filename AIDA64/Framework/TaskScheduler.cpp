#include "pch.h"
#include "TaskScheduler.h"

namespace winrt::AIDA64::Framework
{
    DispatcherTaskScheduler::DispatcherTaskScheduler()
    {
        m_timer = winrt::Microsoft::UI::Xaml::DispatcherTimer{};
        m_timer.Interval(850ms);
        m_timer.Tick([this](auto&, auto&) {
            for (auto& task : m_tasks)
            {
                bool expected{ false };
                if (!task.inFlight.compare_exchange_strong(expected, true))
                {
                    continue;
                }
                auto action = task.action();

                action.Completed([&task](winrt::Windows::Foundation::IAsyncAction const&, [[maybe_unused]] winrt::Windows::Foundation::AsyncStatus status)
                {
                        task.inFlight.store(false);
                });
            }
        });
        m_timer.Start();
    }

    uint64_t DispatcherTaskScheduler::AddTask(std::function<winrt::Windows::Foundation::IAsyncAction()> task)
    {
        uint64_t id = m_nId++;
        m_tasks.emplace_back(id, std::move(task));
        return id;
    }

    void DispatcherTaskScheduler::RemoveTask(uint64_t id)
    {
        for (auto it = m_tasks.begin(); it != m_tasks.end(); ++it)
        {
            if (it->id != id)
            {
                continue;
            }
            if (it->inFlight.load() && it->action)
            {
                it->action().Cancel();
                it->inFlight.store(false);
            }
            m_tasks.erase(it);
            return;
        }
    }

    void DispatcherTaskScheduler::Stop()
    {
        if (m_timer)
        {
            m_timer.Stop();
        }
    }
}


