#ifndef COLOR_HH
#define COLOR_HH
#include <opencv4/opencv2/opencv.hpp>

namespace honeybadger::image
{
class Color
{
  public:
    static cv::Mat convertToGrayscale(const cv::Mat &source);
};
} // namespace honeybadger::image

#endif