#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>
using namespace std;
using namespace cv;
typedef long long ll;
const int N = 0x3f3f3f3f;
Mat src = imread("1.png");
Mat ss;
//绘制轮廓函数
void drawMyContours(string winName, Mat& image, vector<vector<Point>>contours, bool draw_on_blank)
{
	Mat temp;
	if (draw_on_blank)// 在白底上绘制轮廓
	{
		temp = Mat(image.size(), CV_8U, Scalar(255));
		drawContours(
			temp,
			contours,
			-1,//画全部轮廓
			0, //用黑色画
			2);//宽度
	}
	else// 在原图上绘制轮廓
	{
		temp = image.clone();
		drawContours(
			temp,
			contours,
			-1,//画全部轮廓
			Scalar(0,100,0),
			2);//宽度
	}
	//imshow(winName, temp);
	waitKey();
}
void slove_blue()
{
	// 去噪
	GaussianBlur(src, src, Size(3, 3), 1);
	//二值化
	Mat blue;
	inRange(src, Scalar(80, 0, 0), Scalar(255, 85, 85), blue);
	//imshow("b", blue);

	//3.查找轮廓
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	findContours(blue, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
	printf("find %lld contours", contours.size());

	//4.绘制轮廓
	drawMyContours("contours", src, contours, true);

	// 5.筛选轮廓
	// 初始化迭代器
	vector<vector<Point>>::iterator itc = contours.begin();
	vector<Vec4i>::iterator itc_hierarchy = hierarchy.begin();
	//使用层级结构筛选轮廓
	int i = 0;
	while (itc_hierarchy != hierarchy.end())
	{
		//验证轮廓大小
		if (hierarchy[i][3] > 0)// 存在子轮廓/父轮廓
		{
			itc = contours.erase(itc);
			itc_hierarchy = hierarchy.erase(itc_hierarchy);
		}
		else
		{
			++i;
			++itc;
			++itc_hierarchy;
		}
	}
	// 绘制级别筛选后的轮廓
	drawMyContours("contours after hierarchy filtering", src, contours, true);

	// 使用轮廓长度滤波
	// 针对所有轮廓
	itc = contours.begin();
	itc_hierarchy = hierarchy.begin();
	while (itc != contours.end())
	{
		//验证轮廓大小
		if (itc->size() < 300 || itc->size() > 900)
		{
			itc = contours.erase(itc);
			itc_hierarchy = hierarchy.erase(itc_hierarchy);
		}
		else
		{
			++itc;
			++itc_hierarchy;
		}
	}
	// 绘制长度筛选后的轮廓
	drawMyContours("1contours after length filtering", src, contours, true);


	// 6.形状描述子
	// 最小覆盖矩形
	Mat result = src.clone();
	Rect rect1 = boundingRect(contours[0]);
	Rect rect2 = boundingRect(contours[1]);
	rectangle(result, rect1, Scalar(0, 255, 0), 1);
	rectangle(result, rect2, Scalar(0, 255, 0), 1);

	// 7.计算轮廓矩，画重心
	itc = contours.begin();
	while (itc != contours.end())
	{
		// 计算全部轮廓矩
		Moments mom = moments(Mat(*itc++));
		// 画重心
		Point pt = Point(mom.m10 / mom.m00, mom.m01 / mom.m00);//使用前三个矩m00, m01和m10计算重心
		circle(result, pt, 2, (0, 0, 0), 2);
		// 标注重心坐标值
		string text_x = to_string(pt.x);
		string text_y = to_string(pt.y);
		string text = "(" + text_x + ", " + text_y + ")";
		putText(result, text, Point(pt.x + 10, pt.y + 10), FONT_HERSHEY_PLAIN, 1.5, Scalar::all(255), 1, 8, 0);
	}
	//imshow("center", result);
	result.copyTo(ss);
	//imshow("ss", ss);
	//waitKey();
}
void slove_red()
{
	// 去噪
	GaussianBlur(src, src, Size(3, 3), 1);
	//二值化
	Mat red;
	inRange(src, Scalar(0, 0, 80), Scalar(85, 85, 255), red);
	//imshow("r", red);

	//3.查找轮廓
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	findContours(red, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
	printf("find %lld contours", contours.size());

	//4.绘制轮廓
	drawMyContours("contours", src, contours, true);

	// 5.筛选轮廓
	// 初始化迭代器
	vector<vector<Point>>::iterator itc = contours.begin();
	vector<Vec4i>::iterator itc_hierarchy = hierarchy.begin();
	//使用层级结构筛选轮廓
	int i = 0;
	while (itc_hierarchy != hierarchy.end())
	{
		//验证轮廓大小
		if (hierarchy[i][3] > 0)// 存在子轮廓/父轮廓
		{
			itc = contours.erase(itc);
			itc_hierarchy = hierarchy.erase(itc_hierarchy);
		}
		else
		{
			++i;
			++itc;
			++itc_hierarchy;
		}
	}
	printf("%lld contours remaining after hierarchy filtering", contours.size());
	// 绘制级别筛选后的轮廓
	drawMyContours("contours after hierarchy filtering", src, contours, true);

	// 使用轮廓长度滤波
	// 针对所有轮廓
	itc = contours.begin();
	itc_hierarchy = hierarchy.begin();
	while (itc != contours.end())
	{
		//验证轮廓大小
		if (itc->size() < 300 || itc->size() > 900)
		{
			itc = contours.erase(itc);
			itc_hierarchy = hierarchy.erase(itc_hierarchy);
		}
		else
		{
			++itc;
			++itc_hierarchy;
		}
	}
	// 绘制长度筛选后的轮廓
	drawMyContours("1contours after length filtering", src, contours, true);


	// 6.形状描述子
	// 最小覆盖矩形
	Mat result = ss.clone();
	Rect rect1 = boundingRect(contours[0]);
	Rect rect2 = boundingRect(contours[1]);
	Rect rect3 = boundingRect(contours[2]);
	rectangle(result, rect1, Scalar(0, 255, 0), 1);
	rectangle(result, rect2, Scalar(0, 255, 0), 1);
	rectangle(result, rect3, Scalar(0, 255, 0), 1);

	// 7.计算轮廓矩，画重心
	itc = contours.begin();
	while (itc != contours.end())
	{
		// 计算全部轮廓矩
		Moments mom = moments(Mat(*itc++));
		// 画重心
		Point pt = Point(mom.m10 / mom.m00, mom.m01 / mom.m00);//使用前三个矩m00, m01和m10计算重心
		circle(result, pt, 2, (0, 0, 0), 2);
		// 标注重心坐标值
		string text_x = to_string(pt.x);
		string text_y = to_string(pt.y);
		string text = "(" + text_x + ", " + text_y + ")";
		putText(result, text, Point(pt.x + 10, pt.y + 10), FONT_HERSHEY_PLAIN, 1.5, Scalar::all(255), 1, 8, 0);
	}
	imshow("center", result);
	waitKey();

}
int main()
{
	slove_blue();
	slove_red();
	return 0;
}

