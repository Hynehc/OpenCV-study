#define  _CRT_SECURE_NO_WARNINGS 1
//��ɫ���
//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//int main()
//{
//	VideoCapture cap(0);
//	double scale = 0.5;
//	//HSV�ķ�Χ--��ɫ
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
//		cvtColor(frame, hsvMat, COLOR_BGR2HSV);//��ԭͼ����ΪHSV��ʽ
//		frame.copyTo(detectMat);
//		inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), detectMat);
//		//inRange:ԭͼ��3ͨ�����ޣ�3ͨ�����ޣ����
//		imshow("while: in the range", detectMat);
//		imshow("frame", frame);
//		waitKey(30);
//	}
//}




//��ֵ��ͼ��������
//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//void binarization()
//{
//	Mat srcMat = imread("girl.png", 0);//��ȡͼƬת��Ϊ�Ҷ�
//	if (srcMat.empty())//�ж�ͼ���Ƿ���ȡ�ɹ�
//	{
//		return;
//	}
//	Mat bin_Mat, otsu_Mat, adap_Mat;	//����ͼ������
//
//	//��ͨ��ֵ������
//	threshold(srcMat,bin_Mat,100,255, THRESH_BINARY);
//	//����Ҫ�����ͼ��;���ͼ��;��ֵ;���ͼ�����ֵ;��ֵ����
//
//	//���
//	threshold(srcMat, otsu_Mat, 100, 255, THRESH_OTSU);
//
//	//��������Ӧ��ֵ��
//	adaptiveThreshold(srcMat, adap_Mat, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 15, 10);
//	//����ͼ��;���ͼ��;Ԥ���������������ֵ;ָ������Ӧ��ֵ�㷨;ָ����ֵ����;
//	//������С����������������ֵ��һ��ѡ��Ϊ3��5��7......;
//	//����C��ʾ���㷨�йصĲ���������һ���Ӿ�ֵ���Ȩ��ֵ��ȡ�ĳ����������Ǹ�����
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







//����һ������������ͨ���ƶ����������ڶ�ֵ����ֵ
//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
////�ص�����
//void threshold_Mat(int th, void* data)
//{
//	Mat src = *(Mat*)(data);
//	Mat dst;
//	//��ֵ��
//	threshold(src, dst, th, 255, 0);
//	imshow("bar", dst);
//}
//int main()
//{
//	//����ͼ������
//	Mat srcMat;
//	Mat gryMat;
//
//	//��ʼ����������ֵ�������û����ڵĵ��ڷ�Χ
//	int lowth = 0;
//	int maxth = 255;
//
//	srcMat = imread("girl.png");
//
//	//ת��Ϊ�Ҷ�ͼ
//	cvtColor(srcMat, gryMat, COLOR_BGR2GRAY);
//
//	//��ʾ
//	namedWindow("bar");
//	imshow("bar", gryMat);
//
//	createTrackbar("thershold", "bar", &lowth, maxth, threshold_Mat, &gryMat);
//	//�켣��������;�����ռ�����������ͼ�񴰿ڵ�����;��ʼ����ֵ;�����ռ�Ŀ̶ȷ�Χ;
//	//ָ��ص�������ָ��;�û������ص����������ݣ���������켣���¼�
//	waitKey(0);
//}






//Paracosm:
//
//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include <opencv2\imgproc\types_c.h>//�����opencv��������
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//    Mat img = imread("girl.png", 0);//��ȡ����
//
//    //Mat gray;
//    //cvtColor(img, gray, CV_BGR2GRAY);//��ɫת�Ҷ�ͼ
//
//    Mat dst;
//    //threshold(gray, dst, 125, 255, CV_THRESH_OTSU);//���ֻ�ܻҶ�ͼ���Ҷ�ͼת��ֵ��
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
