#include <Color.hh>
#include <gtest/gtest.h>

class PreprocessingColorTest : public testing::Test
{
  private:
    inline static cv::Mat source_;
    inline static cv::Mat expectedGrayscale_;
    inline static cv::Mat expectedThresholding_;

  protected:
    static void SetUpTestSuite()
    {
        source_ = cv::imread("test_data/image/preprocessing/test-pattern.png",
                             cv::IMREAD_UNCHANGED);
        expectedGrayscale_ =
            cv::imread("test_data/image/preprocessing/expected/grayscale.png",
                       cv::IMREAD_UNCHANGED);
        expectedThresholding_ = cv::imread(
            "test_data/image/preprocessing/expected/thresholding.png",
            cv::IMREAD_UNCHANGED);
    }

  public:
    enum numberOfChannels
    {
        monochromatic = 1,
        bgr = 3
    };
    cv::Mat getSource() const
    {
        return source_;
    }

    cv::Mat getGrayscale() const
    {
        return expectedGrayscale_;
    }

    cv::Mat getThresholding() const
    {
        return expectedThresholding_;
    }
};

TEST_F(
    PreprocessingColorTest,
    whenPassAMatrixContainingAnImageTheResultShouldBeAGreyscaleTransformedMatrixThatConformsToTheTemplate)
{
    // given
    honeybadger::image::preprocessing::Color color;
    // when
    const auto expectedResult = color.convertToGrayscale(getSource());
    // then
    ASSERT_EQ(expectedResult.channels(), numberOfChannels::monochromatic);
    ASSERT_EQ(expectedResult.size(), getGrayscale().size());
    ASSERT_EQ(getGrayscale().channels(), numberOfChannels::monochromatic);
    for (auto row{0}; row < expectedResult.rows; ++row)
    {
        for (auto col{0}; col < expectedResult.cols; ++col)
        {
            ASSERT_EQ(expectedResult.at<uchar>(row, col),
                      getGrayscale().at<uchar>(row, col));
        }
    }
}

TEST_F(
    PreprocessingColorTest,
    whenPassTheMatrixWithTheImageShouldGetTheTransformedTrowelAccordingToTheThresholdPoints)
{
    // given
    honeybadger::image::preprocessing::Color color;
    // when
    const auto expectedResult = color.thresholding(getSource());
    // then
    ASSERT_EQ(expectedResult.channels(), numberOfChannels::monochromatic);
    ASSERT_EQ(expectedResult.size(), getGrayscale().size());
    ASSERT_EQ(getThresholding().channels(), numberOfChannels::monochromatic);
    for (auto row{0}; row < expectedResult.rows; ++row)
    {
        for (auto col{0}; col < expectedResult.cols; ++col)
        {
            ASSERT_EQ(expectedResult.at<uchar>(row, col),
                      getThresholding().at<uchar>(row, col));
        }
    }
}
