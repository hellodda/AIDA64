#pragma once
#include <atomic>

using namespace std::chrono_literals;

namespace winrt::AIDA64::Framework
{
    struct task_t
    {
        std::function<winrt::Windows::Foundation::IAsyncAction()> action;
        std::atomic<bool> inFlight{ false };

        task_t(std::function<winrt::Windows::Foundation::IAsyncAction()> a) : action(std::move(a)) {}
        task_t(task_t const&) = delete;
        task_t(task_t&& other) noexcept : action(std::move(other.action)), inFlight(other.inFlight.load()) {}
    };

    struct DispatcherTaskScheduler
    {
        DispatcherTaskScheduler();
        ~DispatcherTaskScheduler() = default;

        void AddTask(std::function<winrt::Windows::Foundation::IAsyncAction()> task);
        void Stop();

    private:
        std::vector<task_t> m_tasks;
        winrt::Microsoft::UI::Xaml::DispatcherTimer m_timer;
    };
}