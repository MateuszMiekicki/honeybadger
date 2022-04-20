#include <Color.hh>
#include <gtest/gtest.h>

TEST(emptySourceMatrix,
     whenPassEmptySourceForThresholdingMatrixShouldThorwException)
{
    // given
    honeybadger::image::preprocessing::Color color;
    // when
    EXPECT_THROW(
        {
            try
            {
                const auto expectedResult = color.thresholding(cv::Mat());
            }
            catch (const std::exception &ex)
            {
                throw;
            }
        },
        std::exception);
    EXPECT_THROW(
        {
            try
            {
                const auto expectedResult = color.thresholding(cv::Mat3b());
            }
            catch (const std::exception &ex)
            {
                throw;
            }
        },
        std::exception);
}

TEST(emptySourceMatrix,
     whenPassEmptySourceForConvertToGrayscaleMatrixShouldThorwException)
{
    // given
    honeybadger::image::preprocessing::Color color;
    // when
    EXPECT_THROW(
        {
            try
            {
                const auto expectedResult = color.convertToGrayscale(cv::Mat());
            }
            catch (const std::exception &ex)
            {
                throw;
            }
        },
        std::exception);
    EXPECT_THROW(
        {
            try
            {
                const auto expectedResult =
                    color.convertToGrayscale(cv::Mat3b());
            }
            catch (const std::exception &ex)
            {
                throw;
            }
        },
        std::exception);
}
