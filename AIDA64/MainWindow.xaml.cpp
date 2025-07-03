#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include <winrt/Windows.UI.Xaml.Interop.h>
#include <ViewModels/CpuPageViewModel.h>
#include <Framework/Utilities.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::AIDA64::implementation
{
	void MainWindow::Inject(winrt::MainViewModel model, std::shared_ptr<ILogger> logger, std::vector<page_data_t> pages)
	{
		m_viewModel = std::move(model);
		m_logger = std::move(logger);
        m_pages = std::move(pages);
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

void winrt::AIDA64::implementation::MainWindow::MainNavigation_ItemInvoked([[maybe_unused]] winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewItemInvokedEventArgs const& args)
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

        auto tag_obj = container.Tag();
        hstring tag;
        try
        {
            tag = winrt::unbox_value<hstring>(tag_obj);
        }
        catch (...)
        {
            return;
        }

            for (auto& page : m_pages)  
            {  
                if (tag == page.tag)  
                {  
                    ContentFrame().Navigate(page.page_type, page.view_model);
                }  
            }
        }
}

void winrt::AIDA64::implementation::MainWindow::ContentFrame_Navigated(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
{
    MainNavigation().IsBackEnabled(ContentFrame().CanGoBack());
}

void winrt::AIDA64::implementation::MainWindow::MainNavigation_BackRequested(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewBackRequestedEventArgs const& args)
{
    ContentFrame().GoBack();
}
