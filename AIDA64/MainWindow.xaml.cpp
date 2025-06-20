#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include <winrt/Windows.UI.Xaml.Interop.h>

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

void winrt::AIDA64::implementation::MainWindow::MainNavigation_ItemInvoked(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewItemInvokedEventArgs const& args)
{
    if (args.IsSettingsInvoked())
    {
        //ContentFrame().Navigate(xaml_typename<SettingsPage>());
    }
    else
    {
        auto container = args.InvokedItemContainer();
        if (!container)
            return;

        auto tagInspectable = container.Tag();
        hstring tag;
        try
        {
            tag = winrt::unbox_value<hstring>(tagInspectable);
        }
        catch (...)
        {
            return;
        }

        if (tag == L"cpu")
        {
            ContentFrame().Navigate(xaml_typename<CpuPage>());
        }
        else if (tag == L"memory")
        {
            //ContentFrame().Navigate(xaml_typename<MemoryPage>());
        }
        else if (tag == L"disk")
        {
            //ContentFrame().Navigate(xaml_typename<DiskPage>());
        }
        else
        {
          
        }
    }
}
