// #include <opencv2/gpu/gpu.hpp>
// #include <opencv2/opencv.hpp>
// #include <iostream>

// int main(int argc, char *argv[])
// {
//     try
//     {
//         cv::Mat src_host = cv::imread("file.png", CV_LOAD_IMAGE_GRAYSCALE);
//         cv::gpu::GpuMat dst, src;
//         src.upload(src_host);

//         cv::gpu::threshold(src, dst, 128.0, 255.0, CV_THRESH_BINARY);

//         cv::Mat result_host;
//         dst.download(result_host);

//         cv::imshow("Result", result_host);
//         cv::waitKey();
//     }
//     catch (const cv::Exception &ex)
//     {
//         std::cout << "Error: " << ex.what() << std::endl;
//     }
//     return 0;
// }

#include <opencv2/opencv.hpp>
#include <stdio.h>
using namespace cv;
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
    Mat image;
    image = imread(argv[1], 1);
    if (!image.data)
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    waitKey(0);
    return 0;
}