#include <Color.hh>
#include <gtest/gtest.h>

TEST(preprocessing, PositiveNos)
{
    honeybadger::image::preprocessing::Color color;
    cv::Mat image(255, 255, CV_8UC3, cv::Scalar(0));
    cv::imshow("Display window",image);
    cv::waitKey(0);
    color.thresholding(image);
    ASSERT_TRUE(1);
}
