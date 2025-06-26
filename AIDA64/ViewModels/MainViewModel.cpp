#include "pch.h"
#include "MainViewModel.h"
#if __has_include("MainViewModel.g.cpp")
#include "MainViewModel.g.cpp"
#endif

namespace winrt::AIDA64::implementation
{
    MainViewModel::MainViewModel()
    {
      
    }
    void MainViewModel::Inject(std::shared_ptr<ILogger> logger)
    {
        m_logger = std::move(logger);
    }
}
