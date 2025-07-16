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

    void DispatcherTaskScheduler::AddTask(std::function<winrt::Windows::Foundation::IAsyncAction()> task)
    {
        m_tasks.emplace_back(std::move(task));
    }

    void DispatcherTaskScheduler::Stop()
    {
        if (m_timer)
        {
            m_timer.Stop();
        }
    }
}


