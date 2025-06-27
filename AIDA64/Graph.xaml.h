#pragma once

#include "Graph.g.h"
#include "winrt/Microsoft.UI.Xaml.h"
#include "winrt/Microsoft.UI.Xaml.Markup.h"
#include "winrt/Microsoft.UI.Xaml.Controls.Primitives.h"
#include <winrt/Windows.UI.h>
#include <winrt/Microsoft.Graphics.Canvas.Brushes.h>
#include <winrt/Microsoft.Graphics.Canvas.Geometry.h>
#include <winrt/Microsoft.Graphics.Canvas.UI.h>
#include <winrt/Microsoft.Graphics.Canvas.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <chrono>

namespace winrt::AIDA64::implementation
{
    struct Graph : GraphT<Graph>
    {
        Graph();

        static winrt::Microsoft::UI::Xaml::DependencyProperty ValuesProperty();
        static winrt::Microsoft::UI::Xaml::DependencyProperty TitleTextProperty();
        static winrt::Microsoft::UI::Xaml::DependencyProperty DefaultColorProperty();
        static winrt::Microsoft::UI::Xaml::DependencyProperty StepSizeProperty();
        static winrt::Microsoft::UI::Xaml::DependencyProperty MaxValueProperty();

        winrt::Windows::Foundation::Collections::IObservableVector<double> Values() const noexcept;
        void Values(winrt::Windows::Foundation::Collections::IObservableVector<double> const& value);
 
        winrt::hstring TitleText() const noexcept;
        void TitleText(winrt::hstring const& value);

        winrt::Windows::UI::Color DefaultColor() const noexcept;
        void DefaultColor(winrt::Windows::UI::Color const& value);

        float StepSize() const noexcept;
        void StepSize(float const& value);

        float MaxValue() const noexcept;
        void MaxValue(float const& value);

        void Pause();
        void Error();

    private:

        static winrt::Microsoft::UI::Xaml::DependencyProperty m_ValuesProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_titleTextProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_defaultColorProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_stepSizeProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_maxValueProperty;

        winrt::event_token m_vectorChangedToken{};


        float m_currentX{ 0.0f };
        float m_maxValue{ 100.0f };
        float m_stepSize{ 30.0f };

        winrt::Windows::Foundation::Size m_graphSize{};

        float getY(float value);

      
        void resizeGraphPoint(float ratio);
        float m_ratio{ 1.0f };

        void makeAnimation();

        void makeAnimation(float y);
        std::chrono::steady_clock::time_point m_start{};

        constexpr static auto BackgroundCircleDistance{ 6 };

    public:

        void OnVectorChanged(winrt::Windows::Foundation::Collections::IObservableVector<double> const& sender, winrt::Windows::Foundation::Collections::IVectorChangedEventArgs const& args);
        void CanvasControl_Draw(winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl const& sender, winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs const& args);
        void UserControl_SizeChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::SizeChangedEventArgs const& e);
    };
}

namespace winrt::AIDA64::factory_implementation
{
    struct Graph : GraphT<Graph, implementation::Graph>
    {
    };
}
