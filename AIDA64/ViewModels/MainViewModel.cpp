#include "pch.h"
#include "MainViewModel.h"
#if __has_include("MainViewModel.g.cpp")
#include "MainViewModel.g.cpp"
#endif

namespace winrt::AIDA64::implementation
{
    MainViewModel::MainViewModel()
    {
        m_pages.Append(NULL);
    }
    void MainViewModel::Inject(std::shared_ptr<ILogger> logger)
    {
        m_logger = std::move(logger);
    }
    ICommand MainViewModel::NavigateCommand()
    {
        if (!m_navigateCommand)
        {
            m_navigateCommand = winrt::make<RelayCommand>([this](/*winrt::IInspectable const& args*/) -> IAsyncAction
            {
                    m_logger->log_info("Navigate Command Invoked");

                    /*if (auto page = args.try_as<INotifyPropertyChanged>())
                    {
                        SelectedPage(page);
                    }*/
                    co_return;
            });
        }
        return m_navigateCommand;
    }
    INotifyPropertyChanged MainViewModel::SelectedPage()
    {
        return m_selectedPage;
    }
    void MainViewModel::SelectedPage(INotifyPropertyChanged const& value)
    {
        if (m_selectedPage != value)
        {
            m_selectedPage = value;

            RaisePropertyChanged(L"SelectedPage");
        }
    }
}
