//
// Created by garrick on 18-9-3.
//

#include <opencv2/opencv.hpp>
#include "sktimshow.hpp"

int main()
{
    skt::connect("127.0.0.1", 9999);
    cv::VideoCapture cap(0);
    while (cap.isOpened())
    {
        cv::Mat image;
        cap >> image;
        skt::imshow("Client", image);
        skt::waitKey(1);
    }
    return 0;
}

