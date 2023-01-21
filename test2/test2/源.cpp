#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <opencv2/opencv.hpp>
#include<vector>
using namespace std;
using namespace cv;

//图像的颜色分离
//int main()
//{
//	Mat src_color = imread("qq.png");
//	vector<Mat> channels;
//	split(src_color, channels);
//	Mat B = channels.at(0);
//	Mat G = channels.at(1);
//	Mat R = channels.at(2);
//	imshow("red", R);
//	imshow("blue", B);
//	imshow("green", G);
//	imshow("originl Mat", src_color);
//	waitKey(0);
//}




//调用摄像头

//int main()
//{
//    VideoCapture cap(0);
//    Mat img;
//
//    while (1)
//    {
//        cap >> img;
//        if (img.empty())
//            break;
//        namedWindow("img", WINDOW_NORMAL);
//        imshow("img", img);
//        if (27 == waitKey(20))
//            break;
//    }
//
//    return 0;
//}


//int main()
//{
//	VideoCapture cap(0);
//	Mat img;
//	while (1)
//	{
//		cap >> img;
//		if (img.empty())
//			break;
//
//		imshow("img", img);
//		waitKey(30);
//	}
//}



//int main()
//{
//    VideoCapture cap;
//    cap.open(0);
//    if (!cap.isOpened())
//    {
//        cout << -1 << endl;
//    }
//    double fps = cap.get(CAP_PROP_FPS);
//    cout << "fps" << fps << endl;
//    while (1)
//    {
//        Mat frame;
//        cap >> frame;
//        imshow("frame", frame);
//    }
//    waitKey(30);
//}



//
//int main()
//{
//	VideoCapture cap(0);
//	Mat img;
//	while (1)
//	{
//		cap >> img;
//		imshow("img", img);
//		waitKey(30);
//	}
//}




//画圆
//int main()
//{
//	Point pt;
//	Mat picture = imread("girl.png");
//	pt.x = 1000;
//	pt.y = 1000;
//	circle(picture, pt, 500, CV_RGB(255, 255, 0), 1, 8, 0);
//	//目标图像，圆心，半径，颜色，圆的线条粗细，-1为实心圆，邻接关系和偏移，一般设置默认值8和0
//	imshow("1", picture);
//	waitKey(0);
//}


//画线段
//int main()
//{
//	Mat img = imread("girl.png");
//	Point pt1, pt2;
//	pt1.x = 10, pt1.y = 10;
//	pt2.x = 1000, pt2.y = 1000;
//	line(img, Point(10,10), Point(100,100), CV_RGB(255, 0, 0), 1, 8, 0);
//	imshow("img", img);
//	waitKey(0);
//}



//画矩形
//int main()
//{
//	Mat img = imread("girl.png");
//	Rect rect;
//	rect.x = 100, rect.y = 100;
//	rect.width = 100;
//	rect.height = 100;
//	rectangle(img, rect, CV_RGB(255, 255, 255), -1, 8, 0);
//	imshow("img", img);
//	waitKey(0);
//}




