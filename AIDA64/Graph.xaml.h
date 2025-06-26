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

        static winrt::Microsoft::UI::Xaml::DependencyProperty PointsProperty();
        static winrt::Microsoft::UI::Xaml::DependencyProperty TitleTextProperty();
        static winrt::Microsoft::UI::Xaml::DependencyProperty DefaultColorProperty();

        winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Foundation::Point> Points() const noexcept;
        void Points(winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Foundation::Point> const& value);
 
        winrt::hstring TitleText() const noexcept;
        void TitleText(winrt::hstring const& value);

        winrt::Windows::UI::Color DefaultColor() const noexcept;
        void DefaultColor(winrt::Windows::UI::Color const& value);

        void SetPoints(winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Foundation::Point> const& points);
        void AddPoint(winrt::Windows::Foundation::Point const& point);
        void SetTotal(uint64_t bytes) { m_total = bytes; }

        void Pause();
        void Error();

    private:

        static winrt::Microsoft::UI::Xaml::DependencyProperty m_pointsProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_titleTextProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_defaultColorProperty;

        uint64_t m_total{};
        uint64_t m_currentMax = 1024;

        winrt::Windows::Foundation::Size m_graphSize{};

        float getX(uint64_t progressBytes);
        float getY(uint64_t speed);

      
        void resizeGraphPoint(float ratio);
        float m_ratio{ 1.0f };

        void makeAnimation();

        void makeAnimation(float y);
        std::chrono::steady_clock::time_point m_start{};

        constexpr static auto BackgroundCircleDistance = 6;

    public:
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
