#define  _CRT_SECURE_NO_WARNINGS 1
/*
//图像形态学处理，分别对图像进行腐蚀、膨胀、开运算、闭运算
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
	//读入灰度图
	Mat src = imread("1and2.png", 0);
	//定义图像容器
	Mat thresh_Mat, dilate_Mat, erode_Mat, open_Mat, close_Mat;

	//大津法二值化
	threshold(src, thresh_Mat, 100, 255, THRESH_OTSU);

	//定义结构元素
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5), Point(-1, -1));
	//表示内核的形状,矩形：MORPH_RECT;交叉形：MORPH_CROSS;椭圆形：MORPH_ELLIPSE;
	//内核的尺寸
	//锚点的位置

	//腐蚀
	erode(thresh_Mat, erode_Mat, kernel, Point(-1, -1), 1);
	//src;dst;腐蚀操作的内核，一般用3*3的核；锚的位置，一般用（-1，-1）；使用函数的次数

	//膨胀
	dilate(thresh_Mat, dilate_Mat, kernel, Point(-1, -1), 1);

	//开运算--先腐蚀后膨胀
	morphologyEx(thresh_Mat, open_Mat, MORPH_OPEN, kernel, Point(-1, -1), 1);
	
	//闭运算--先膨胀后腐蚀
	morphologyEx(thresh_Mat, close_Mat, MORPH_CLOSE, kernel, Point(-1, -1), 1);
	//表示形态学运算的类型，如MORPH_OPEN、MORPH_CLOSE分别代表开运算和闭运算

	imshow("thresh", thresh_Mat);
	imshow("erode", erode_Mat);
	imshow("dilate", dilate_Mat);
	imshow("open", open_Mat);
	imshow("close", close_Mat);
	waitKey(0);
}
*/







//连通域标记
//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//int main()
//{
//	Mat src = imread("1and2.png",0);
//
//	//转灰
//	/*Mat gry;
//	cvtColor(src, gry, COLOR_BGRA2GRAY);*/
//
//	Mat stats, centroids, labels, thresh_Mat;
//
//	//大津法
//	threshold(src, thresh_Mat, 100, 255, THRESH_OTSU);
//
//	//进行连通域标记
//	int nComp = connectedComponentsWithStats(thresh_Mat, labels, stats, centroids, 8, CV_32S);
//	//输入8位单通道二值图像;
//	//输出和原图image一样大的标记图，label对应于表示是当前像素是第几个轮廓，背景置0
//	//输出nccomps（标签数）×5的矩阵 ，表示每个连通区域的外接矩形和面积（pixel）
//	//对应的是轮廓的中心点。nccomps×2的矩阵 表示每个连通区域的质心
//	//使用8邻域或者4邻域
//	//输出标签的数据类型
//
//	for (int i = 0;i < nComp;i++)
//	{
//		cout << i << endl;
//		cout << stats.at<int>(i, 4) << endl;
//		cout << stats.at<int>(i, 2) << endl;
//		cout << stats.at<int>(i, 3) << endl;
//		cout << endl;
//	}
//	//减去背景0，并输出
//	cout << "硬币个数为：" << nComp - 1 << endl;
//
//	//通过颜色表现连通域
//	Mat resultMat = cv::Mat::zeros(src.size(), CV_8UC3);
//	vector<Vec3b>colors(nComp);
//	//背景使用黑色
//	colors[0] = Vec3b(0, 0, 0);
//	//使用随机函数randu,随机产生颜色
//	for (int i = 1;i < nComp;i++)
//	{
//		colors[i] = Vec3b(rand() / 255, rand() / 255, rand() / 255);
//	}
//	//对所以像素按照连通域编号进行着色
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
//	//对识别出的连通域加最小外接边框
//	for (int i = 1;i < nComp;i++)
//	{
//		//定义Rect类--矩形的左上角坐标以及长宽
//		Rect bandbox;
//		bandbox.x = stats.at<int>(i, 0);
//		bandbox.y = stats.at<int>(i, 1);
//		bandbox.width = stats.at<int>(i, 2);
//		bandbox.height = stats.at<int>(i, 3);
//		//画出矩形
//		rectangle(resultMat, bandbox, 255, 1, 8, 0);
//		//CV_IN_OUT； Rect类成员；颜色信息；线的粗细；邻接关系，一般设置默认值；偏移，一般设0
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
//原点计数
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
	//定义结构元素
	Mat element = getStructuringElement(MORPH_RECT, Size(5, 5), Point(-1, -1));
	//腐蚀
	erode(thresh_Mat, erode_Mat, element, Point(-1, -1), 2);
	//进行联通域标记
	int nComp = connectedComponentsWithStats(erode_Mat, labels, stats, centroids, 8, CV_32S);
	cout << "原点个数为：" << nComp - 1 << endl;
	imshow("1", erode_Mat);
	waitKey(0);
}
*/





//回型针计数
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
//	//开运算
//	morphologyEx(thresh_Mat, open_Mat, MORPH_OPEN, elemet, Point(-1, -1), 1);
//
//	int nComp = connectedComponentsWithStats(open_Mat, labels, stats, centroids, 8, CV_32S);
//	
//	//比较长宽比，筛选掉干扰连通域
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
//	cout << "回型针个数为：" << nComp - 1 << endl;
//	imshow("1", open_Mat);
//	waitKey(0);
//}