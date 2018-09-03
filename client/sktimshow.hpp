#pragma once
#include <opencv2/core.hpp>

#ifndef UNIUBI_API
#ifdef _MSC_VER
#ifdef UNIUBI_EXPORTS
#define UNIUBI_API __declspec(dllexport)
#else  // UNIUBI_EXPORTS
#define UNIUBI_API __declspec(dllimport)
#endif // UNIUBI_EXPORTS
#else  // _MSC_VER
#define UNIUBI_API
#endif // _MSC_VER
#endif // UNIUBI_API

namespace skt {
    UNIUBI_API int connect(const cv::String& ip, int port);
    UNIUBI_API void imshow(const cv::String& winname, cv::InputArray mat);
    UNIUBI_API int waitKey(int delay = 0);
}