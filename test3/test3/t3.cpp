#define  _CRT_SECURE_NO_WARNINGS 1
//肤色检测
//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//int main()
//{
//	VideoCapture cap(0);
//	double scale = 0.5;
//	//HSV的范围--肤色
//	double i_minH = 0, i_maxH = 20;
//	double i_minS = 43, i_maxS = 255;
//	double i_minV = 55, i_maxV = 255;
//	while (1)
//	{
//		Mat frame;
//		Mat hsvMat;
//		Mat detectMat;
//		cap >> frame;
//		/*Size ResImgSiz = Size(frame.cols * scale, frame.rows * scale);
//		Mat rframe = Mat(ResImgSiz, frame.type());
//		resize(frame, hsvMat, INTER_LINEAR);*/
//		cvtColor(frame, hsvMat, COLOR_BGR2HSV);//将原图设置为HSV格式
//		frame.copyTo(detectMat);
//		inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), detectMat);
//		//inRange:原图；3通道下限；3通道上限，结果
//		imshow("while: in the range", detectMat);
//		imshow("frame", frame);
//		waitKey(30);
//	}
//}




//二值化图像函数调用
//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//void binarization()
//{
//	Mat srcMat = imread("girl.png", 0);//读取图片转化为灰度
//	if (srcMat.empty())//判断图像是否提取成功
//	{
//		return;
//	}
//	Mat bin_Mat, otsu_Mat, adap_Mat;	//定义图像容器
//
//	//普通二值化方法
//	threshold(srcMat,bin_Mat,100,255, THRESH_BINARY);
//	//输入要处理的图像;输出图像;阈值;输出图像最大值;阈值类型
//
//	//大津法
//	threshold(srcMat, otsu_Mat, 100, 255, THRESH_OTSU);
//
//	//区域自适应二值化
//	adaptiveThreshold(srcMat, adap_Mat, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 15, 10);
//	//输入图像;输出图像;预设满足条件的最大值;指定自适应阈值算法;指定阈值类型;
//	//邻域块大小，用来计算区域阈值，一般选择为3、5、7......;
//	//参数C表示与算法有关的参数，它是一个从均值或加权均值提取的常数，可以是负数。
//
//	imshow("bin_Mat", bin_Mat);
//	imshow("otsu_Mat", otsu_Mat);
//	imshow("adap_Mat", adap_Mat);
//	
//	waitKey(0);
//}
//int main()
//{
//	binarization();
//}
//
//







//创建一个滑动条，可通过移动滑动条调节二值化阈值
//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
////回调函数
//void threshold_Mat(int th, void* data)
//{
//	Mat src = *(Mat*)(data);
//	Mat dst;
//	//二值化
//	threshold(src, dst, th, 255, 0);
//	imshow("bar", dst);
//}
//int main()
//{
//	//定义图像容器
//	Mat srcMat;
//	Mat gryMat;
//
//	//初始化滑动条的值，并设置滑动节的调节范围
//	int lowth = 0;
//	int maxth = 255;
//
//	srcMat = imread("girl.png");
//
//	//转化为灰度图
//	cvtColor(srcMat, gryMat, COLOR_BGR2GRAY);
//
//	//显示
//	namedWindow("bar");
//	imshow("bar", gryMat);
//
//	createTrackbar("thershold", "bar", &lowth, maxth, threshold_Mat, &gryMat);
//	//轨迹条的名字;滑动空间用于依附的图像窗口的名称;初始化阈值;滑动空间的刻度范围;
//	//指向回调函数的指针;用户传给回调函数的数据，用来处理轨迹条事件
//	waitKey(0);
//}






//Paracosm:
//
//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include <opencv2\imgproc\types_c.h>//添加让opencv函数可用
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//    Mat img = imread("girl.png", 0);//读取函数
//
//    //Mat gray;
//    //cvtColor(img, gray, CV_BGR2GRAY);//彩色转灰度图
//
//    Mat dst;
//    //threshold(gray, dst, 125, 255, CV_THRESH_OTSU);//大津法只能灰度图，灰度图转二值化
//    //threshold(img, dst, 125, 255, THRESH_OTSU);
//    adaptiveThreshold(img, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 15, 10);
//
//    imshow("src", img);
//    //imshow("gray", gray);
//    imshow("dst", dst);
//    waitKey(0);
//
//    return 0;
//}
