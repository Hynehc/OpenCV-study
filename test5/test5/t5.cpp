#define  _CRT_SECURE_NO_WARNINGS 1
//��������ĥƤ����
//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//int main()
//{
//	VideoCapture cap(0);
//
//	//��ɫ
//	double i_minH = 0;
//	double i_maxH = 20;
//	
//	//��ɫ��ɫ���Ͷ�
//	double i_minS = 43;
//	double i_maxS = 255;
//
//	//��ɫ��ɫ����
//	double i_minV = 55;
//	double i_maxV = 255;
//
//	while (1)
//	{
//		Mat frame, hsvMat, maskMat, objectMat, guss_Mat;
//		cap >> frame;
//		//��ԭͼת��Ϊhsv���͵�ͼƬ
//		cvtColor(frame, hsvMat, COLOR_BGR2HSV);
//		//��detecMat���г�ʼ��
//		frame.copyTo(maskMat);
//		//����inRange������ͼƬ����hsvɸѡ��ѡ���������֣�
//		inRange(hsvMat, (i_minH, i_minS, i_minV), (i_maxH, i_maxS, i_maxV), maskMat);
//		//ԭͼ���������
//		frame.copyTo(objectMat);
//		//��ͼ����и�˹�˲�
//		GaussianBlur(frame, guss_Mat, Size(5, 5), 3, 0);
//		//��˹�˲����������������Ŀ��ͼ��
//		guss_Mat.copyTo(objectMat, maskMat);////��ԭͼ��ȡ��Ŀ��ͼ�������㣩
//		imshow("before", frame);
//		imshow("after", objectMat);
//		waitKey(30);
//	}
//}