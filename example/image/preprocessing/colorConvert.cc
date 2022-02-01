#include <honeybadger/image/preprocessing/Color.hh>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        using namespace honeybadger::image::preprocessing;
        const cv::Mat img = cv::imread(argv[1]);
        imshow("img", img);
        const auto grayscale = Color::convertToGrayscale(img);
        imshow("grayscale", grayscale);
        const auto binarization = Color::thresholding(img);
        imshow("binarization", binarization);
        cv::waitKey(0);
    }
}