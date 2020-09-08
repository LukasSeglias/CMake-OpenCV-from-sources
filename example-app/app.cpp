#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main() {

    const char* filename = "opencv.png";
    cv::Mat original = cv::imread(filename, cv::IMREAD_COLOR);

    if (!original.data) {
        std::cout << "Could not open or find the image: " << filename << std::endl;
        return -1;
    }

    cv::imshow("OpenCV", original);
    cv::waitKey(0);

    return 0;
}