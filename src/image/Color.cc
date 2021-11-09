#include <Color.hh>
#include <opencv4/opencv2/opencv.hpp>

namespace honeybadger::image
{
cv::Mat Color::convertToGrayscale(const cv::Mat &source)
{
    auto grayscale = cv::Mat();
    cv::cvtColor(source, grayscale, cv::COLOR_BGRA2GRAY);
    return grayscale;
}
} // namespace honeybadger::image