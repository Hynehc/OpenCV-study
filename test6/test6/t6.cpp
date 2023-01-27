//#define  _CRT_SECURE_NO_WARNINGS 1
///*
////用canny算子进行边缘提取
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
//		//通过sobel算子得到x、y方向上的梯度
//		Sobel(frame, dx, CV_16S, 1, 0, 3);
//		Sobel(frame, dy, CV_16S, 0, 1, 3);
//		//输入图像;x/y方向上的梯度;输出的格式;1，0表示对x或者对y方向求微分的次数;3表示sobel核的大小
//
//		//进行sobel边缘提取
//		Canny(dx, dy, canny_mat1, 20, 60);
//		//输入图像x/y方向上的梯度;输出边缘图像，单通道;阈值1;阈值2
//		cvtColor(frame, gry_mat, COLOR_BGR2GRAY);//转化为灰度图，在进行边缘提取
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
////旋转及缩放以及仿射变换 投影变换
//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//int main()
//{
//	Mat src = imread("1.png");
//
//	//旋转及缩放
//	//初始化旋转角度以及缩放尺度
//	float angle = -10.0;
//	float scale = 1;
//
//	//设置旋转中心
//	Point2f center(src.cols * 0.5, src.rows * 0.5);
//
//	//获得变换矩阵
//	const Mat affine_matrix_zoom = getRotationMatrix2D(center, angle, scale);
//	//旋转的中心点;旋转的角度;图像缩放因子
//
//	Mat dst1;
//
//	//利用仿射变换函数
//	warpAffine(src, dst1, affine_matrix_zoom, src.size());
//	imshow("src", src);
//	imshow("dst1", dst1);
//
//	//**************************************************************************
//	//仿射变换
//	Mat affine_Mat;
//	//变换前3点坐标
//	const Point2f src_pt[] = 
//	{
//		  Point2f(200,200),
//		  Point2f(250,200),
//		  Point2f(200,100),
//	};
//	//变换后3点坐标
//	const Point2f dst_pt[] =
//	{
//		  Point2f(300,100),
//		  Point2f(300,50),
//		  Point2f(200,100),
//	};
//	//计算仿射变换后的矩阵
//	//获得变换矩阵
//	const Mat affine_matrix = getAffineTransform(src_pt, dst_pt);//原始图像的点;目标图像的点
//	warpAffine(src, affine_Mat, affine_matrix, src.size());
//	imshow("affine", affine_Mat);
//
//	//*****************************************************************************
//	//投影变换
//	Mat perspective_Mat;
//	//变换前4点坐标
//	cv::Point2f pts1[] = {
//		cv::Point2f(150,150),
//		cv::Point2f(150,300),
//		cv::Point2f(350,300),
//		cv::Point2f(350,150),
//
//	};
//	//变换后4点坐标
//	cv::Point2f pts2[] = {
//		cv::Point2f(200,150),
//		cv::Point2f(200,300),
//		cv::Point2f(340,270),
//		cv::Point2f(340,180),
//	};
//	//投影变换矩阵生成(3*3)
//	Mat perspective_matrix = getPerspectiveTransform(pts1, pts2);
//	//投影变换
//	warpPerspective(src, perspective_Mat, perspective_matrix, src.size());
//	imshow("perspective", perspective_Mat);
//	waitKey(0);
//}