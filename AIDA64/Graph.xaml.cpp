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

        this->Loaded([this](auto&&, auto&&)
        {
                m_graphSize.Height = this->ActualHeight();
                m_graphSize.Width = this->ActualWidth();
                UpdateBrushColor();
        });
    }

    winrt::Windows::Foundation::Collections::IObservableVector<double> Graph::Values() const noexcept
    {
        return winrt::unbox_value<winrt::Windows::Foundation::Collections::IObservableVector<double>>(GetValue(m_ValuesProperty));
    }

    void Graph::Values(winrt::Windows::Foundation::Collections::IObservableVector<double> const& value)
    {
        SetValue(m_ValuesProperty, winrt::box_value(value));
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

    float Graph::StepSize() const noexcept
    {
        return winrt::unbox_value<float>(GetValue(m_stepSizeProperty));
    }

    void Graph::StepSize(float const& value)
    {
        SetValue(m_stepSizeProperty, winrt::box_value(value));
    }

    float Graph::MaxValue() const noexcept
    {
        return winrt::unbox_value<float>(GetValue(m_maxValueProperty));
    }

    void Graph::MaxValue(float const& value)
    {
        SetValue(m_maxValueProperty, winrt::box_value(value));
    }

    Microsoft::UI::Xaml::DependencyProperty Graph::ValuesProperty()
    {
        return m_ValuesProperty;
    }

    Microsoft::UI::Xaml::DependencyProperty Graph::TitleTextProperty()
    {
        return m_titleTextProperty;
    }

    Microsoft::UI::Xaml::DependencyProperty Graph::DefaultColorProperty()
    {
        return m_defaultColorProperty;
    }

    Microsoft::UI::Xaml::DependencyProperty Graph::StepSizeProperty()
    {
        return m_stepSizeProperty;
    }

    Microsoft::UI::Xaml::DependencyProperty Graph::MaxValueProperty()
    {
        return m_maxValueProperty;
    }

  

    void Graph::OnVectorChanged(
        winrt::Windows::Foundation::Collections::IObservableVector<double> const& sender,
        winrt::Windows::Foundation::Collections::IVectorChangedEventArgs const& args)
    {
        if (args.CollectionChange() == winrt::Windows::Foundation::Collections::CollectionChange::ItemInserted)
        {
            auto index = args.Index();
            float raw = static_cast<float>(sender.GetAt(index));
            float y = getY(raw);
       
            auto shapePoints = Shape().Points();

            if (shapePoints.Size() == 0)
            {
                shapePoints.Append({ 0, m_graphSize.Height });
            }
            if (shapePoints.Size() >= 2)
            {
                shapePoints.SetAt(shapePoints.Size() - 1, { m_currentX, y });
            }

            shapePoints.Append({ m_currentX, m_graphSize.Height });

            makeAnimation(y);

            m_currentX += m_stepSize;

            if (m_currentX > m_graphSize.Width)
            {
                m_currentX = 0;
                shapePoints.Clear();
                shapePoints.Append({ 0, m_graphSize.Height });
            }
        }
    }

    float Graph::getY(float value)
    {
        if (m_maxValue <= 0)
            return m_graphSize.Height;

        float clamped = std::min(value, m_maxValue);
        float normalized = clamped / m_maxValue;
        return m_graphSize.Height * (1.0f - normalized); 
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

    void Graph::UpdateBrushColor()
    {
        winrt::Microsoft::UI::Xaml::Media::LinearGradientBrush brush;
        brush.StartPoint({ 0.0f, 0.0f });
        brush.EndPoint({ 0.0f, 1.0f });

        auto baseColor = DefaultColor();

        winrt::Microsoft::UI::Xaml::Media::GradientStop bottomStop;
        bottomStop.Color(baseColor);
        bottomStop.Offset(0.0);

        winrt::Microsoft::UI::Xaml::Media::GradientStop topStop;
        topStop.Color(winrt::Windows::UI::ColorHelper::FromArgb(0x10, baseColor.R, baseColor.G, baseColor.B));
        topStop.Offset(1.0);

        brush.GradientStops().Append(bottomStop);
        brush.GradientStops().Append(topStop);

        Shape().Fill(brush);
    }

}


namespace winrt::AIDA64::implementation
{
    Microsoft::UI::Xaml::DependencyProperty Graph::m_titleTextProperty = register_property<AIDA64::Graph, winrt::hstring>(L"TitleText");
    Microsoft::UI::Xaml::DependencyProperty Graph::m_stepSizeProperty = register_property<AIDA64::Graph, float>(L"StepSize");
    Microsoft::UI::Xaml::DependencyProperty Graph::m_maxValueProperty = register_property<AIDA64::Graph, float>(L"MaxValue");

    Microsoft::UI::Xaml::DependencyProperty Graph::m_ValuesProperty =
        register_property<AIDA64::Graph, winrt::Windows::Foundation::Collections::IObservableVector<double>>(
            L"Points",
            winrt::Microsoft::UI::Xaml::PropertyMetadata{ nullptr,
                [](auto d, auto e)
                {
                    if (auto graph = d.try_as<AIDA64::implementation::Graph>())
                    {
                        if (graph->m_vectorChangedToken.value != 0)
                        {
                            if (auto oldVec = e.OldValue().try_as<winrt::Windows::Foundation::Collections::IObservableVector<double>>())
                            {
                                oldVec.VectorChanged(graph->m_vectorChangedToken);
                            }
                            graph->m_vectorChangedToken = {};
                        }

                        if (auto newVec = e.NewValue().try_as<winrt::Windows::Foundation::Collections::IObservableVector<double>>())
                        {
                            auto weakGraph = graph->get_weak();

                            graph->m_vectorChangedToken = newVec.VectorChanged(
                                [weakGraph](auto const& sender, auto const& args)
                                {
                                    if (auto strong = weakGraph.get())
                                    {
                                        strong->OnVectorChanged(sender, args);
                                    }
                           });
                        }
                    }
                }
            }
        );

    Microsoft::UI::Xaml::DependencyProperty Graph::m_defaultColorProperty =
     register_property<AIDA64::Graph, winrt::Windows::UI::Color>(
        L"DefaultColor",
        winrt::Microsoft::UI::Xaml::PropertyMetadata{
            winrt::box_value(winrt::Windows::UI::Colors::LightGreen()),
            [](auto d, auto e)
            {
                if (auto graph = d.try_as<AIDA64::implementation::Graph>())
                {
                    graph->UpdateBrushColor();
                }
            }
    });

}