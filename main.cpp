#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main(int argc, char *argv[])
{

    Mat img=imread("d:/pic/image.jpg");
    Mat backImg=imread("d:/pic/back.jpg");
    imshow("01",img);

    //1.转hsv
    Mat hsv;
    cvtColor(img,hsv,COLOR_BGR2HSV);

    //2.提取红色
    Mat mark;
    inRange(hsv,Scalar(0,100,180),Scalar(10,255,255),mark);
    imshow("2",mark);
    Mat mark1;
    inRange(hsv,Scalar(156,120,130),Scalar(180,255,255),mark1);
    imshow("3",mark1);
    Mat finMark=mark+mark1;
    imshow("4",finMark);

    //3.取反
    Mat finMark1;
    bitwise_not(finMark,finMark);//只有人物在
    imshow("test08",finMark);

    img.copyTo(backImg,finMark);
    imshow("5",backImg);

    //img.copyTo(backImg,finMark1);
    //imshow("6",backImg);






    /*Mat img=imread("d:/image2.png");
    imshow("test05",img);

    Mat hsv;
    cvtColor(img,hsv,COLOR_BGR2HSV);
    imshow("test06",hsv);

    Mat mask;
    inRange(hsv,Scalar(100,43,46),Scalar(124,255,255),mask);
    imshow("test07",mask);

    //取反
    bitwise_not(mask,mask);
    imshow("test08",mask);

    Mat redBack =Mat::zeros(img.size(),img.type());
    redBack=Scalar(40,40,200);
    imshow("test09",redBack);

    img.copyTo(redBack,mask);
    imshow("test10",redBack);*/



   /*Mat img = imread("d:/image1.jpg");
   imshow("test01",img);

   Mat blurImg;
   blur(img,blurImg,Size(50,50));
   imshow("test02",blurImg);

   Mat grayImg;
   cvtColor(img,grayImg,COLOR_BGR2GRAY);
   imshow("test03",grayImg);

   //转化为二值化图片
   Mat threImg;
   threshold(grayImg,threImg,100,255,THRESH_BINARY);
   imshow("test04",threImg);*/

   waitKey(0);
   return 0;
}
