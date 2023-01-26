#define  _CRT_SECURE_NO_WARNINGS 1
//简易人脸磨皮程序
//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//int main()
//{
//	VideoCapture cap(0);
//
//	//肤色
//	double i_minH = 0;
//	double i_maxH = 20;
//	
//	//肤色颜色饱和度
//	double i_minS = 43;
//	double i_maxS = 255;
//
//	//肤色颜色亮度
//	double i_minV = 55;
//	double i_maxV = 255;
//
//	while (1)
//	{
//		Mat frame, hsvMat, maskMat, objectMat, guss_Mat;
//		cap >> frame;
//		//将原图转化为hsv类型的图片
//		cvtColor(frame, hsvMat, COLOR_BGR2HSV);
//		//对detecMat进行初始化
//		frame.copyTo(maskMat);
//		//利用inRange函数对图片进行hsv筛选（选出人脸部分）
//		inRange(hsvMat, (i_minH, i_minS, i_minV), (i_maxH, i_maxS, i_maxV), maskMat);
//		//原图拷入输出中
//		frame.copyTo(objectMat);
//		//对图像进行高斯滤波
//		GaussianBlur(frame, guss_Mat, Size(5, 5), 3, 0);
//		//高斯滤波后的人脸部分送入目标图中
//		guss_Mat.copyTo(objectMat, maskMat);////从原图中取出目标图像（与运算）
//		imshow("before", frame);
//		imshow("after", objectMat);
//		waitKey(30);
//	}
//}