
#include <iostream>
#include <opencv2/opencv.hpp>
#include "xsocket.hpp"

using namespace cv;
using namespace std;

int port = 0;

void listenClient(int port) {

	net::init();
	net::socket sock(net::af::inet, net::sock::dgram, port);

	if (!sock.good()) {
		std::cerr << "error creating socket" << std::endl;
		return ;
	}

	std::cout << "listening on port: " << sock.getlocaladdr().get_port() << std::endl;

	cv::Mat image;
	char buf[65536];
	while (true) {
		std::vector<uchar> decode;
		int n = sock.recv(buf, sizeof(buf));
		int pos = 0;
		while (pos<n)
		{
			decode.push_back(buf[pos++]);
		}
		buf[n] = 0;
		image = cv::imdecode(decode, CV_LOAD_IMAGE_COLOR);
		cv::imshow("server", image);
		cv::waitKey(1);
	}

}
int main()	{
	listenClient(9999);
	return 0;
}

