#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::AIDA64::implementation
{
	void MainWindow::Inject(winrt::MainViewModel const& model, std::shared_ptr<ILogger> logger)
	{
		m_viewModel = model;
		m_logger = std::move(logger);
	}

	void MainWindow::Setup()
	{
		ExtendsContentIntoTitleBar(true);
	}

	AIDA64::MainViewModel MainWindow::MainViewModel()
	{
		return m_viewModel;
	}
}
