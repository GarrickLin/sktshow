#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "xsocket.hpp"
#include "sktimshow.hpp"

using namespace cv;
using namespace std;
std::string ip = "";
int port = 0;
net::socket ClientSock;
net::endpoint remoteAddr;
const int buffspace = 1920*1080*3*4;
char encodeImg[buffspace];

namespace skt 
{
	int connect(const String& ip, int port) 
	{
		net::init();
		ClientSock = net::socket(net::af::inet, net::sock::dgram);
		if (!ClientSock.good()) {
			std::cerr << "error creating socket" << std::endl;
			return 0;
		}
		remoteAddr=net::endpoint (ip, port);
		return 1;
	}

	void imshow(const String& winname, InputArray mat) 
	{
		if (mat.empty())
		{
			std::cerr << "empty image\n";
			return ;
		}
		if (!ClientSock.good()) {
			std::cerr << "Not connect any ip address yet!" << std::endl;
			return;
		}
		std::vector<uchar> data_encode;
		std::vector<int> quality;
		quality.push_back(CV_IMWRITE_JPEG_QUALITY);
		quality.push_back(50);
		imencode(".jpg", mat, data_encode, quality);
		int nSize = data_encode.size();
		memcpy(encodeImg, data_encode.data(), nSize);
		ClientSock.sendto(encodeImg, nSize, remoteAddr);
		memset(&encodeImg, 0, nSize);
	}

	int waitKey(int delay ) 
	{
//		cv::waitKey(delay);
		return 0;
	}
}