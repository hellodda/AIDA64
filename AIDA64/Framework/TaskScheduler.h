#pragma once
#include <atomic>

using namespace std::chrono_literals;

namespace winrt::AIDA64::Framework
{
    struct task_t
    {
        uint64_t id;
        std::function<winrt::Windows::Foundation::IAsyncAction()> action;
        std::atomic<bool> inFlight{ false };

        task_t(uint64_t id, std::function<winrt::Windows::Foundation::IAsyncAction()> a) : id(id), action(std::move(a)) {}
        task_t(task_t&& other) noexcept : id(other.id), action(std::move(other.action)), inFlight(other.inFlight.load()) {}
        task_t(task_t const&) = delete;               
        task_t& operator=(task_t const&) = delete;    
        task_t& operator=(task_t&& other) noexcept
        {
            if (this != &other)
            {
                action = std::move(other.action);
                inFlight.store(other.inFlight.load());
                id = other.id;
            }
            return *this;
        }
    };

    struct DispatcherTaskScheduler
    {
        DispatcherTaskScheduler();
        ~DispatcherTaskScheduler() = default;

        [[nodiscard]] uint64_t AddTask(std::function<winrt::Windows::Foundation::IAsyncAction()> task);
        void RemoveTask(uint64_t id);
        void Stop();

    private:
        std::vector<task_t> m_tasks;
        winrt::Microsoft::UI::Xaml::DispatcherTimer m_timer;
        uint64_t m_nId{ 1 };
    };
}