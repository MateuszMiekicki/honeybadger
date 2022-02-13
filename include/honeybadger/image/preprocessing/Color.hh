#ifndef HONEYBADGER_COLOR_HH
#define HONEYBADGER_COLOR_HH
#include <opencv4/opencv2/opencv.hpp>

namespace honeybadger::image::preprocessing
{
/// @brief The class responsible for preprocessing the image for ocr. Simple
/// operations on images.
class Color
{
  public:
    /// @brief A static method that converts a matrix to grayscale.
    /// @param source matrix to convert.
    static cv::Mat convertToGrayscale(const cv::Mat &source);
    /// @brief A static method for image binarization. Converts it to black and
    /// white.
    /// @param source matrix to convert.
    /// @note No need to care about the source of the image. The method will
    /// internally convert it to grayscale.
    static cv::Mat thresholding(const cv::Mat &source);
};
} // namespace honeybadger::image::preprocessing

#endif