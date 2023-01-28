//#define  _CRT_SECURE_NO_WARNINGS 1
////�ֶ�ʵ�֣�ͨ�� HOG�Ƚ�ͼ�����ƶ�
//#include<iostream>
//#include<cstring>
//#include<opencv2/opencv.hpp>
//#include<opencv2/highgui/highgui.hpp>
//#include "Դ.h"
//using namespace std;
//using namespace cv;
////�ֶ�ʵ�� HOG
//int calcHOG(Mat src, float* hist, int nAngle, int cellSize)
//{
//	if (cellSize > src.cols || cellSize > src.rows) return -1;
//	//��������
//	int nX = src.cols / cellSize;
//	int nY = src.rows / cellSize;
//	int binAngle = 360 / nAngle;
//	//�����ݶȼ��Ƕ�
//	Mat gx, gy;
//	Mat mag, angle;
//	Sobel(src, gx, CV_32F, 1, 0, 1);
//	Sobel(src, gy, CV_32F, 0, 1, 1);
//	// x�����ݶȣ�y�����ݶȣ��ݶȣ��Ƕȣ������������or�Ƕ�
//	// Ĭ���ǻ���radians��ͨ�����һ����������ѡ��Ƕ�degrees
//
//	cartToPolar(gx, gy, mag, angle, true);
//
//	Rect roi;
//	roi.x = 0;
//	roi.y = 0;
//	roi.width = cellSize;
//	roi.height = cellSize;
//	for (int i = 0;i < nY;i++)
//		for (int j = 0;j < nX;j++)
//		{
//			Mat roiMat;
//			Mat roiMag;
//			Mat roiAgl;
//			roi.x = j * cellSize;
//			roi.y = j * cellSize;
//
//			//��ֵͼ��
//			roiMat = src(roi);
//			roiMag = mag(roi);
//			roiAgl = angle(roi);
//
//			//��ǰcell��һ��Ԫ���������е�λ��
//			int head = (i * nX + j) * nAngle;
//		
//			for (int n = 0;n < roiMat.rows;n++)
//				for (int m = 0;m < roiMat.cols;m++)
//				{
//					//����Ƕ����ĸ�bin��ͨ��int�Զ�ȡ��ʵ��
//					int pos = (int)(roiAgl.at<float>(n, m) / binAngle);
//					//�����ص��ֵΪȨ��
//					hist[head + pos] += roiMag.at<float>(n, m);
//				}
//		}
//	return 0;
//}
//float normL2(float* Hist1, float* Hist2, int size)
//{
//	float sum = 0;
//	for (int i = 0;i < size;i++)
//	{
//		sum += (Hist1[i] - Hist2[i]) * (Hist1[i] - Hist2[i]);
//	}
//	sum = sqrt(sum);
//	return sum;
//}
//int main()
//{
//	Mat refMat = imread("hogTemplate.jpg",0);
//	Mat plMat = imread("img1.jpg",0);
//	Mat bgMat = imread("img2.jpg",0);
//	
//	int nAngle = 8;
//	int blockSize = 16;
//	int nX = refMat.cols / blockSize;
//	int nY = refMat.rows / blockSize;
//	int bins = nX * nY * nAngle;
//
//	float* ref_hist = new float[bins];
//	memset(ref_hist, 0, sizeof(float) * bins);
//	float* pl_hist = new float[bins];
//	memset(pl_hist, 0, sizeof(float) * bins);
//	float* bg_hist = new float[bins];
//	memset(bg_hist, 0, sizeof(float) * bins);
//
//	int reCode = 0;
//	//������������ͼƬ��HOG
//	reCode = calcHOG(refMat, ref_hist, nAngle, blockSize);
//	reCode = calcHOG(plMat, pl_hist, nAngle, blockSize);
//	reCode = calcHOG(bgMat, bg_hist, nAngle, blockSize);
//
//	//����ֱ��ͼ����
//	float dis1 = normL2(ref_hist, pl_hist, bins);
//	float dis2 = normL2(ref_hist, bg_hist, bins);
//
//	cout << "distance between reference and img1:" << dis1 << endl;
//	cout << "distance between reference and img2:" << dis2 << endl;
//
//	(dis1 <= dis2) ? (cout << "img1 is similar" << endl) : (cout << "img2 is similar" << endl);
//
//	imshow("ref", refMat);
//	imshow("img1", plMat);
//	imshow("img2", bgMat);
//
//	waitKey(0);
//
//	delete[] ref_hist;
//	delete[] pl_hist;
//	delete[] bg_hist;
//	destroyAllWindows();
//
//	return 0;
//}
//
