#define  _CRT_SECURE_NO_WARNINGS 1
/*
//ͼ����̬ѧ�����ֱ��ͼ����и�ʴ�����͡������㡢������
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
	//����Ҷ�ͼ
	Mat src = imread("1and2.png", 0);
	//����ͼ������
	Mat thresh_Mat, dilate_Mat, erode_Mat, open_Mat, close_Mat;

	//��򷨶�ֵ��
	threshold(src, thresh_Mat, 100, 255, THRESH_OTSU);

	//����ṹԪ��
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5), Point(-1, -1));
	//��ʾ�ں˵���״,���Σ�MORPH_RECT;�����Σ�MORPH_CROSS;��Բ�Σ�MORPH_ELLIPSE;
	//�ں˵ĳߴ�
	//ê���λ��

	//��ʴ
	erode(thresh_Mat, erode_Mat, kernel, Point(-1, -1), 1);
	//src;dst;��ʴ�������ںˣ�һ����3*3�ĺˣ�ê��λ�ã�һ���ã�-1��-1����ʹ�ú����Ĵ���

	//����
	dilate(thresh_Mat, dilate_Mat, kernel, Point(-1, -1), 1);

	//������--�ȸ�ʴ������
	morphologyEx(thresh_Mat, open_Mat, MORPH_OPEN, kernel, Point(-1, -1), 1);
	
	//������--�����ͺ�ʴ
	morphologyEx(thresh_Mat, close_Mat, MORPH_CLOSE, kernel, Point(-1, -1), 1);
	//��ʾ��̬ѧ��������ͣ���MORPH_OPEN��MORPH_CLOSE�ֱ��������ͱ�����

	imshow("thresh", thresh_Mat);
	imshow("erode", erode_Mat);
	imshow("dilate", dilate_Mat);
	imshow("open", open_Mat);
	imshow("close", close_Mat);
	waitKey(0);
}
*/







//��ͨ����
//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//int main()
//{
//	Mat src = imread("1and2.png",0);
//
//	//ת��
//	/*Mat gry;
//	cvtColor(src, gry, COLOR_BGRA2GRAY);*/
//
//	Mat stats, centroids, labels, thresh_Mat;
//
//	//���
//	threshold(src, thresh_Mat, 100, 255, THRESH_OTSU);
//
//	//������ͨ����
//	int nComp = connectedComponentsWithStats(thresh_Mat, labels, stats, centroids, 8, CV_32S);
//	//����8λ��ͨ����ֵͼ��;
//	//�����ԭͼimageһ����ı��ͼ��label��Ӧ�ڱ�ʾ�ǵ�ǰ�����ǵڼ���������������0
//	//���nccomps����ǩ������5�ľ��� ����ʾÿ����ͨ�������Ӿ��κ������pixel��
//	//��Ӧ�������������ĵ㡣nccomps��2�ľ��� ��ʾÿ����ͨ���������
//	//ʹ��8�������4����
//	//�����ǩ����������
//
//	for (int i = 0;i < nComp;i++)
//	{
//		cout << i << endl;
//		cout << stats.at<int>(i, 4) << endl;
//		cout << stats.at<int>(i, 2) << endl;
//		cout << stats.at<int>(i, 3) << endl;
//		cout << endl;
//	}
//	//��ȥ����0�������
//	cout << "Ӳ�Ҹ���Ϊ��" << nComp - 1 << endl;
//
//	//ͨ����ɫ������ͨ��
//	Mat resultMat = cv::Mat::zeros(src.size(), CV_8UC3);
//	vector<Vec3b>colors(nComp);
//	//����ʹ�ú�ɫ
//	colors[0] = Vec3b(0, 0, 0);
//	//ʹ���������randu,���������ɫ
//	for (int i = 1;i < nComp;i++)
//	{
//		colors[i] = Vec3b(rand() / 255, rand() / 255, rand() / 255);
//	}
//	//���������ذ�����ͨ���Ž�����ɫ
//	for (int y = 0;y < src.rows;y++)
//	{
//		for (int x = 0;x < src.cols;x++)
//		{
//			int label = labels.at<int>(y, x);
//			CV_Assert(0 <= label && label <= nComp);
//			resultMat.at<Vec3b>(y, x) = colors[label];
//		}
//	}
//
//	//��ʶ�������ͨ�����С��ӱ߿�
//	for (int i = 1;i < nComp;i++)
//	{
//		//����Rect��--���ε����Ͻ������Լ�����
//		Rect bandbox;
//		bandbox.x = stats.at<int>(i, 0);
//		bandbox.y = stats.at<int>(i, 1);
//		bandbox.width = stats.at<int>(i, 2);
//		bandbox.height = stats.at<int>(i, 3);
//		//��������
//		rectangle(resultMat, bandbox, 255, 1, 8, 0);
//		//CV_IN_OUT�� Rect���Ա����ɫ��Ϣ���ߵĴ�ϸ���ڽӹ�ϵ��һ������Ĭ��ֵ��ƫ�ƣ�һ����0
//
//	}
//	imshow("thresh", thresh_Mat);
//	imshow("resules", resultMat);
//	moveWindow("thresh__", src.cols, 20);
//	moveWindow("resules__", src.cols * 2, 20);
//	
//	waitKey(0);
//
//}





/*
//ԭ�����
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
	Mat src = imread("3.jpg",0);
	Mat gry = 255 - src;
	Mat stats, centroids, labels, thresh_Mat, erode_Mat;
	threshold(gry, thresh_Mat, 100, 255, THRESH_OTSU);
	//����ṹԪ��
	Mat element = getStructuringElement(MORPH_RECT, Size(5, 5), Point(-1, -1));
	//��ʴ
	erode(thresh_Mat, erode_Mat, element, Point(-1, -1), 2);
	//������ͨ����
	int nComp = connectedComponentsWithStats(erode_Mat, labels, stats, centroids, 8, CV_32S);
	cout << "ԭ�����Ϊ��" << nComp - 1 << endl;
	imshow("1", erode_Mat);
	waitKey(0);
}
*/





//���������
//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//int main()
//{
//	Mat src = imread("4.png",0);
//	Mat gry = 255 - src;
//	Mat stats, labels, centroids, thresh_Mat, open_Mat;
//	threshold(gry, thresh_Mat, 100, 255, THRESH_OTSU);
//	Mat elemet = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
//	//������
//	morphologyEx(thresh_Mat, open_Mat, MORPH_OPEN, elemet, Point(-1, -1), 1);
//
//	int nComp = connectedComponentsWithStats(open_Mat, labels, stats, centroids, 8, CV_32S);
//	
//	//�Ƚϳ���ȣ�ɸѡ��������ͨ��
//	for (int i = 1;i < nComp;i++)
//	{
//		int width = stats.at<int>(i, 2);
//		int height = stats.at<int>(i, 3);
//		int ratio = height / width;
//		if (ratio > 10)
//		{
//			nComp--;
//		}
//	}
//	cout << "���������Ϊ��" << nComp - 1 << endl;
//	imshow("1", open_Mat);
//	waitKey(0);
//}