#include <honeybadger/image/preprocessing/Color.hh>
#include <opencv2/opencv.hpp>

int main()
{
    using namespace honeybadger::image::preprocessing;
    {
        std::string jpg = "img.jpg";
        cv::Mat imgjpg = cv::imread(jpg);
        const auto grayscale = Color::convertToGrayscale(imgjpg);
    }
    {
        std::string png = "img.png";
        cv::Mat imgpng = cv::imread(png);
        const auto binarization = Color::thresholding(imgpng);
    }
}