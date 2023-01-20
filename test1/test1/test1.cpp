#define  _CRT_SECURE_NO_WARNINGS 1
#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
//int main()
//{
//	Mat image = imread("girl.png");
//	imshow("image", image);
//	waitKey(0);
//	return 0;
//}

int main()
{
	/*Mat m1(2, 2, CV_8UC3, Scalar(0, 0, 255));
	cout << "m1" << endl << m1 << endl;
	Mat m2(2, 5, CV_8UC3, 1);
	cout << "m2" << endl << m2 << endl;
	int height = m2.rows;
	int width = m2.cols;
	cout << height << " " << width << endl;
	Mat m3, m4, m5;
	m3.create(3, 4, CV_8UC3);
	m4 = m3;
	m3.copyTo(m5);
	randu(m3, Scalar(0), Scalar(255));
	cout << m3 << endl << m4 << endl << m5 << endl;*/


	Mat m6, m7;
	m6.create(3, 4, CV_8UC1);
	m7.create(3, 4, CV_8UC3);
	for (int j = 0;j < m6.rows;j++)
	{
		uchar* data = m6.ptr<uchar>(j);
		for (int i = 0;i < m6.cols;i++)
		{
			data[i] = j;
		}
	}
	cout << m6 << endl;


	for (int j = 0;j < m7.rows;j++)
	{
		for (int i = 0;i < m7.cols;i++)
		{
			m7.at<Vec3b>(j, i)[0] = j;
			m7.at<Vec3b>(j, i)[1] = j + 1;
			m7.at<Vec3b>(j, i)[2] = j + 2;
		}
	}
	cout << m7.rows << " " << m7.cols << endl;
	cout << m7 << endl;
}