//#define  _CRT_SECURE_NO_WARNINGS 1
///*
////��canny���ӽ��б�Ե��ȡ
//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//int main()
//{
//	VideoCapture cap(0);
//	Mat frame;
//	
//
//	while (1)
//	{
//		cap.read(frame);
//		Mat dx, dy, canny_mat1, canny_mat2, gry_mat;
//
//		//ͨ��sobel���ӵõ�x��y�����ϵ��ݶ�
//		Sobel(frame, dx, CV_16S, 1, 0, 3);
//		Sobel(frame, dy, CV_16S, 0, 1, 3);
//		//����ͼ��;x/y�����ϵ��ݶ�;����ĸ�ʽ;1��0��ʾ��x���߶�y������΢�ֵĴ���;3��ʾsobel�˵Ĵ�С
//
//		//����sobel��Ե��ȡ
//		Canny(dx, dy, canny_mat1, 20, 60);
//		//����ͼ��x/y�����ϵ��ݶ�;�����Եͼ�񣬵�ͨ��;��ֵ1;��ֵ2
//		cvtColor(frame, gry_mat, COLOR_BGR2GRAY);//ת��Ϊ�Ҷ�ͼ���ڽ��б�Ե��ȡ
//		Canny(gry_mat, canny_mat2, 20, 60);
//		imshow("1", canny_mat1);
//		imshow("2", canny_mat2);
//		waitKey(30);
//	}
//
//}*/
//
//
//
//
//
//
////��ת�������Լ�����任 ͶӰ�任
//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//int main()
//{
//	Mat src = imread("1.png");
//
//	//��ת������
//	//��ʼ����ת�Ƕ��Լ����ų߶�
//	float angle = -10.0;
//	float scale = 1;
//
//	//������ת����
//	Point2f center(src.cols * 0.5, src.rows * 0.5);
//
//	//��ñ任����
//	const Mat affine_matrix_zoom = getRotationMatrix2D(center, angle, scale);
//	//��ת�����ĵ�;��ת�ĽǶ�;ͼ����������
//
//	Mat dst1;
//
//	//���÷���任����
//	warpAffine(src, dst1, affine_matrix_zoom, src.size());
//	imshow("src", src);
//	imshow("dst1", dst1);
//
//	//**************************************************************************
//	//����任
//	Mat affine_Mat;
//	//�任ǰ3������
//	const Point2f src_pt[] = 
//	{
//		  Point2f(200,200),
//		  Point2f(250,200),
//		  Point2f(200,100),
//	};
//	//�任��3������
//	const Point2f dst_pt[] =
//	{
//		  Point2f(300,100),
//		  Point2f(300,50),
//		  Point2f(200,100),
//	};
//	//�������任��ľ���
//	//��ñ任����
//	const Mat affine_matrix = getAffineTransform(src_pt, dst_pt);//ԭʼͼ��ĵ�;Ŀ��ͼ��ĵ�
//	warpAffine(src, affine_Mat, affine_matrix, src.size());
//	imshow("affine", affine_Mat);
//
//	//*****************************************************************************
//	//ͶӰ�任
//	Mat perspective_Mat;
//	//�任ǰ4������
//	cv::Point2f pts1[] = {
//		cv::Point2f(150,150),
//		cv::Point2f(150,300),
//		cv::Point2f(350,300),
//		cv::Point2f(350,150),
//
//	};
//	//�任��4������
//	cv::Point2f pts2[] = {
//		cv::Point2f(200,150),
//		cv::Point2f(200,300),
//		cv::Point2f(340,270),
//		cv::Point2f(340,180),
//	};
//	//ͶӰ�任��������(3*3)
//	Mat perspective_matrix = getPerspectiveTransform(pts1, pts2);
//	//ͶӰ�任
//	warpPerspective(src, perspective_Mat, perspective_matrix, src.size());
//	imshow("perspective", perspective_Mat);
//	waitKey(0);
//}