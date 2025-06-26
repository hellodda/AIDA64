#include "pch.h"
#include "Graph.xaml.h"
#if __has_include("Graph.g.cpp")
#include "Graph.g.cpp"
#endif

#include <Framework/Utilities.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::AIDA64::implementation
{
    Graph::Graph()
    {
        InitializeComponent();
    }

    winrt::Microsoft::UI::Xaml::DependencyProperty Graph::PointsProperty()
    {
        return m_pointsProperty;
    }

    winrt::Microsoft::UI::Xaml::DependencyProperty Graph::TitleTextProperty()
    {
        return m_titleTextProperty;
    }

    winrt::Microsoft::UI::Xaml::DependencyProperty Graph::DefaultColorProperty()
    {
        return m_defaultColorProperty;
    }

    winrt::Microsoft::UI::Xaml::DependencyProperty Graph::m_pointsProperty =
     register_property<AIDA64::Graph, winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Foundation::Point>>(
        L"Points",
        winrt::Microsoft::UI::Xaml::PropertyMetadata{
            nullptr,
            [](auto sender, auto args)
            {
                if (auto control = sender.try_as<AIDA64::Graph>())
                {
                    auto points = args.NewValue()
                        .try_as<winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Foundation::Point>>();
                    if (points)
                    {
                        control.SetPoints(points);
                    }
                }
            }
        }
    );

    winrt::Microsoft::UI::Xaml::DependencyProperty Graph::m_titleTextProperty = register_property<AIDA64::Graph, winrt::hstring>(L"TitleText");
    winrt::Microsoft::UI::Xaml::DependencyProperty Graph::m_defaultColorProperty = register_property<AIDA64::Graph, winrt::Windows::UI::Color>(L"DefaultColor");

    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Foundation::Point> Graph::Points() const noexcept
    {
        return winrt::unbox_value<winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Foundation::Point>>(GetValue(m_pointsProperty));
    }

    void Graph::Points(winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Foundation::Point> const& value)
    {
        SetValue(m_pointsProperty, winrt::box_value(value));
    }

    winrt::hstring Graph::TitleText() const noexcept
    {
        return winrt::unbox_value<winrt::hstring>(GetValue(m_titleTextProperty));
    }

    void Graph::TitleText(winrt::hstring const& value)
    {
        SetValue(m_titleTextProperty, winrt::box_value(value));
    }

    winrt::Windows::UI::Color Graph::DefaultColor() const noexcept
    {
        return winrt::unbox_value<winrt::Windows::UI::Color>(GetValue(m_defaultColorProperty));
    }

    void Graph::DefaultColor(Windows::UI::Color const& value)
    {
        SetValue(m_defaultColorProperty, winrt::box_value(value));
    }

    void Graph::SetPoints(winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Foundation::Point> const& points)
    {
        auto shapePoints = Shape().Points();
        shapePoints.Clear();

        for (auto const& pt : points)
        {
            shapePoints.Append(pt);
        }

        if (points.Size() > 0)
        {
            auto last = points.GetAt(points.Size() - 1);
            shapePoints.Append({ last.X, m_graphSize.Height });
        }
    }

    void Graph::AddPoint(winrt::Windows::Foundation::Point const& point)
    {
        auto shapePoints = Shape().Points();

        if (shapePoints.Size() == 0)
        {
            shapePoints.Append({ 0, m_graphSize.Height });
        }

        if (shapePoints.Size() >= 2)
        {
            shapePoints.SetAt(shapePoints.Size() - 1, point);
        }

        shapePoints.Append({ point.X, m_graphSize.Height }); 
    }

    float Graph::getX(uint64_t progressBytes)
    {
        return m_graphSize.Width * (static_cast<float>(progressBytes) / m_total);
    }

    float Graph::getY(uint64_t speed)
    {
        return m_graphSize.Height * (1.0f - static_cast<float>(speed) / m_currentMax / m_ratio);
    }

    void Graph::resizeGraphPoint(float ratio)
    {
        auto const m_ratioCopy = m_ratio;
        m_ratio *= ratio;
        ScaleDownAnimation().To(m_ratio);
        ScaleDown().Begin();
    }

    void Graph::makeAnimation(float y)
    {
        constexpr winrt::Windows::Foundation::TimeSpan duration{ std::chrono::milliseconds{300} };

        winrt::Microsoft::UI::Xaml::Media::Animation::Storyboard s;
        winrt::Microsoft::UI::Xaml::Media::Animation::DoubleAnimation lineTranslate;
        winrt::Microsoft::UI::Xaml::Media::Animation::DoubleAnimation textTranslate;

        winrt::Microsoft::UI::Xaml::Media::Animation::Storyboard::SetTarget(lineTranslate, LineTranslate());
        winrt::Microsoft::UI::Xaml::Media::Animation::Storyboard::SetTargetProperty(lineTranslate, L"Y");
        winrt::Microsoft::UI::Xaml::Media::Animation::Storyboard::SetTarget(textTranslate, TextTranslate());
        winrt::Microsoft::UI::Xaml::Media::Animation::Storyboard::SetTargetProperty(textTranslate, L"Y");

        lineTranslate.Duration({ duration, winrt::Microsoft::UI::Xaml::DurationType::TimeSpan });
        textTranslate.Duration({ duration, winrt::Microsoft::UI::Xaml::DurationType::TimeSpan });

        winrt::Microsoft::UI::Xaml::Media::Animation::ExponentialEase ease;
        ease.Exponent(7);
        ease.EasingMode(winrt::Microsoft::UI::Xaml::Media::Animation::EasingMode::EaseOut);
        lineTranslate.EasingFunction(ease);
        textTranslate.EasingFunction(ease);


        lineTranslate.To(y);
        textTranslate.To(y);
        s.Children().Append(lineTranslate);
        s.Children().Append(textTranslate);
        s.Begin();
    }

    void Graph::makeAnimation()
    {
        auto const p = Shape().Points().GetAt(Shape().Points().Size() - 2);
        auto const y = m_graphSize.Height - ((m_graphSize.Height - p.Y) * m_ratio);
        makeAnimation(y);
    }

    void Graph::CanvasControl_Draw(winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl const& sender, winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs const& args)
    {
        auto drawingSession = args.DrawingSession();

        auto const width = sender.ActualWidth();
        auto const height = sender.ActualHeight();
        auto const color = winrt::Windows::UI::ColorHelper::FromArgb(32, 255, 255, 255);

        for (int i = 0; i < width; i += BackgroundCircleDistance)
        {
            for (int j = 0; j < height; j += BackgroundCircleDistance)
            {
                drawingSession.FillCircle(i, j, 1, color);
            }
        }
    }

    void Graph::UserControl_SizeChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::SizeChangedEventArgs const& e)
    {
        auto const newSize = e.NewSize();
        if (m_graphSize != newSize && newSize.Width != 0 && newSize.Height != 0)
        {
            m_graphSize = e.NewSize();

           
            auto points = Shape().Points();
            auto const pointsCount = points.Size();
            for (int i = 0; i < pointsCount; ++i)
            {

            }
        }
    }
    void Graph::Pause()
    {
        winrt::Microsoft::UI::Xaml::VisualStateManager::GoToState(*this, L"Pause", false);
    }

    void Graph::Error()
    {
        winrt::Microsoft::UI::Xaml::VisualStateManager::GoToState(*this, L"Error", false);
    }
}
