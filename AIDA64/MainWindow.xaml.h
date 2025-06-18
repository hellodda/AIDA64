#pragma once

#include "MainWindow.g.h"
#include <Framework/ProcessService.h>

namespace winrt::AIDA64::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow()
        {
            InitializeComponent();
            Models(m_models);
            LoadProcessesAsync();
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);

        IObservableVector<AIDA64::ProcessModel> Models();
        void Models(IObservableVector<AIDA64::ProcessModel> const& value);

        IAsyncAction MainWindow::LoadProcessesAsync()
        {
            auto uiDispatcher = winrt::Windows::System::DispatcherQueue::GetForCurrentThread();

            co_await winrt::resume_background();

            Framework::WmiDataContext context;
            Framework::ProcessService service(context);
            IVector<AIDA64::ProcessModel> processes;
            try {
                processes = co_await service.GetAllProcessesAsync();
            }
            catch (winrt::hresult_error const& e) {

                co_return;
            }

            if (uiDispatcher) {
                co_await winrt::resume_foreground(uiDispatcher);
            }

            //m_models.Clear();
            for (auto& model : processes) {
                m_models.Append(model);
                OutputDebugString(L"ASJASIHAUIJSAI");
                OutputDebugString(model.Name().c_str());
                //this->Bindings->Update();
            }
        }

    private:

        IObservableVector<AIDA64::ProcessModel> m_models = single_threaded_observable_vector<AIDA64::ProcessModel>();
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
