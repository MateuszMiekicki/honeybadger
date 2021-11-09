#include <Color.hh>
#include <opencv4/opencv2/opencv.hpp>

namespace honeybadger::image::preprocessing
{
cv::Mat Color::convertToGrayscale(const cv::Mat &source)
{
    auto grayscale = cv::Mat();
    cv::cvtColor(source, grayscale, cv::COLOR_BGRA2GRAY);
    return grayscale;
}

cv::Mat Color::binarization(const cv::Mat &source)
{

    const auto threshold{127};
    const auto upperBound{255};
    auto thresholdOutput = cv::Mat();
    cv::threshold(convertToGrayscale(source), thresholdOutput, threshold,
                  upperBound, cv::THRESH_BINARY);
    return thresholdOutput;
}
} // namespace honeybadger::image::preprocessing