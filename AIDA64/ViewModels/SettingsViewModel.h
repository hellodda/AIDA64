#pragma once

#include "SettingsViewModel.g.h"

#include <Models/VisualConfiguration.h>

#include <Helpers/BindableBase.h>
#include <Helpers/RelayCommand.h>


namespace winrt
{
    using namespace Windows::Foundation;
    using namespace Windows::Foundation::Collections;
    using namespace Microsoft::UI::Xaml::Data;
    using namespace AIDA64::Helpers;
}

namespace winrt::AIDA64::implementation
{
    struct SettingsViewModel : SettingsViewModelT<SettingsViewModel>
    {
        SettingsViewModel();


        Windows::Foundation::Collections::IObservableVector<AIDA64::VisualConfiguration> Backdrops() const noexcept;
        void Backdrops(Windows::Foundation::Collections::IObservableVector<AIDA64::VisualConfiguration> const& value);

        void ChangeBackdrop(hstring const& value);
        void BatterySaveEnabled(bool value);
        bool BatterySaveEnabled() const noexcept;

    private:
        winrt::IObservableVector<AIDA64::VisualConfiguration> m_backdrops = single_threaded_observable_vector<AIDA64::VisualConfiguration>();
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct SettingsViewModel : SettingsViewModelT<SettingsViewModel, implementation::SettingsViewModel>
    {
    };
}
