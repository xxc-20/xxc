#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{

    Mat frame;
    Mat backImg;
    VideoCapture vid(0);

    while(vid.read(frame)){
        backImg=imread("D:/pic/back04.png"); //背景图片
        imshow("test01",frame);
        //imshow("back",backImg);
        //1.转hsv
        Mat hsv;
        cvtColor(frame,hsv,COLOR_BGR2HSV);

        //2.抠图
        Mat mask;
        inRange(hsv,Scalar(100,43,46),Scalar(124,255,255),mask);//保留蓝色区域，但实际想用背景图覆盖蓝色区域
        //所以3.取反
        Mat mask1;
        bitwise_not(mask,mask1);
        //4.用原图片调用copyTo实现对模板的覆盖
        frame.copyTo(backImg,mask1);
        imshow("finalImg",backImg);

        waitKey(50);
    }

    return 0;
}
