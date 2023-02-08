#define  _CRT_SECURE_NO_WARNINGS 1
#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<tchar.h>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<vector>
using namespace std;
using namespace cv;
typedef long long ll;
//Mat frame,pic;
Mat src;
Mat ss;
Mat result;
Rect rect1, rect2, rect3;
const int N = 0x3f3f3f3f;
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
			Scalar(0, 100, 0),
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
		if (itc->size() < 150 || itc->size() > 700)
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
	result = src.clone();
	int sz = contours.size();
	if (sz == 1) rect1 = boundingRect(contours[0]), rectangle(result, rect1, Scalar(0, 255, 0), 1);
	else if (sz == 2)
	{
		rect1 = boundingRect(contours[0]), rectangle(result, rect1, Scalar(0, 255, 0), 1);
		rect2 = boundingRect(contours[1]), rectangle(result, rect2, Scalar(0, 255, 0), 1);
	}
	else if (sz >= 3)
	{
		rect1 = boundingRect(contours[0]), rectangle(result, rect1, Scalar(0, 255, 0), 1);
		rect2 = boundingRect(contours[1]), rectangle(result, rect2, Scalar(0, 255, 0), 1);
		rect3 = boundingRect(contours[2]), rectangle(result, rect3, Scalar(0, 255, 0), 1);
	}
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
	contours.clear();
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
	//printf("find %lld contours", contours.size());

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
		if (itc->size() < 200 || itc->size()>900)
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
	result = ss.clone();
	int sz = contours.size();
	if (sz==1) rect1 = boundingRect(contours[0]), rectangle(result, rect1, Scalar(0, 255, 0), 1);
	else if (sz == 2)
	{
		rect1 = boundingRect(contours[0]), rectangle(result, rect1, Scalar(0, 255, 0), 1);
		rect2 = boundingRect(contours[1]), rectangle(result, rect2, Scalar(0, 255, 0), 1);
	}
	else if (sz >= 3)
	{
		rect1 = boundingRect(contours[0]), rectangle(result, rect1, Scalar(0, 255, 0), 1);
		rect2 = boundingRect(contours[1]), rectangle(result, rect2, Scalar(0, 255, 0), 1);
		rect3 = boundingRect(contours[2]), rectangle(result, rect3, Scalar(0, 255, 0), 1);
	}
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
	contours.clear();
	waitKey();

}

void  Video_To_Image(string filename);
void  Image_To_Video();
int main()
{
	string video_name = "11.mp4";//注意，使用string时，若不用using namespace std，需要使用std::string
	Video_To_Image(video_name);
	Image_To_Video();
	return 0;
}
void Video_To_Image(string filename)
{
	cout << "---------------Video_To_Image-----------------" << endl;
	cv::VideoCapture capture(filename);
	if (!capture.isOpened())
	{
		cout << "open video error";
	}
	/*CV_CAP_PROP_POS_MSEC – 视频的当前位置（毫秒）
	CV_CAP_PROP_POS_FRAMES – 视频的当前位置（帧）
	CV_CAP_PROP_FRAME_WIDTH – 视频流的宽度
	CV_CAP_PROP_FRAME_HEIGHT – 视频流的高度
	CV_CAP_PROP_FPS – 帧速率（帧 / 秒）*/
	int frame_width = (int)capture.get(CAP_PROP_FRAME_WIDTH);
	int frame_height = (int)capture.get(CAP_PROP_FRAME_HEIGHT);
	float frame_fps = capture.get(CAP_PROP_FPS);
	int frame_number = capture.get(CAP_PROP_FRAME_COUNT);//总帧数

	int num = 0;//统计帧数
	cv::Mat img;
	string img_name;
	char image_name[20];
	cv::namedWindow("MyVideo", WINDOW_AUTOSIZE);
	while (true)
	{
		cv::Mat frame;
		//从视频中读取一个帧
		bool bSuccess = capture.read(frame);
		if (!bSuccess)
		{
			cout << "不能从视频文件读取帧" << endl;
			break;
		}
		src = frame.clone();
		slove_blue(), slove_red();
		//imshow("1", result);
		waitKey(2);
		//在MyVideo窗口上显示当前帧
		//imshow("MyVideo", frame);
		//保存的图片名
		//sprintf(const_cast<char*>(img_name.data()), "%s%d%s", "image", ++num, ".jpg");//保存的图片名
		sprintf(image_name, "%s%d%s", "image", ++num, ".jpg");//保存的图片名
		img_name = image_name;
		imwrite(img_name, result);//保存保存一帧图片
		if (cv::waitKey(30) == 27 )
		{
			cout << "按下ESC键" << endl;
			break;
		}
	}
	capture.release();//这句话貌似不需要
}

void Image_To_Video()
{
	cout << "---------------Video_To_Image-----------------" << endl;
	char image_name[20];
	string s_image_name;
	cv::VideoWriter writer;
	int isColor = 1;
	int frame_fps = 30;
	int frame_width = 640;
	int frame_height = 480;
	using namespace cv;
	string video_name = "out.avi";
	writer = VideoWriter(video_name, ('X', 'V', 'I', 'D'), frame_fps, Size(frame_width, frame_height), isColor);
	cv::namedWindow("image to video", WINDOW_AUTOSIZE);
	int num = 1000;//输入的图片总张数
	int i = 0;
	Mat img;
	while (i <= 520)
	{
		sprintf(image_name, "%s%d%s", "image", ++i, ".jpg");
		s_image_name = image_name;
		img = imread(s_image_name);//读入图片
		if (!img.data)//判断图片调入是否成功
		{
			cout << "Could not load image file...\n" << endl;
		}
		imshow("image to video", img);
		//写入
		writer.write(img);
		if (cv::waitKey(30) == 27 )
		{
			cout << "按下ESC键" << endl;
			break;
		}
	}
}





//int main()
//{
//
//
//	VideoCapture cap;
//
//	cap.set(3, 300);
//
//	cap.open("11.mp4");
//	if (!cap.isOpened())
//		std::cout << "not opened";
//
//	Mat frame;
//	int i = 0;
//	char c;
//
//	char filename[100];
//
//
//	namedWindow("v窗口", WINDOW_NORMAL);
//	namedWindow("v窗口", WINDOW_AUTOSIZE);
//	moveWindow("v窗口", 20, 20);
//	resizeWindow("v窗口", 512, 512);
//
//	while (1)
//	{
//
//		cap >> frame;
//		if (frame.empty())
//		{
//			std::cout << "empty";
//			break;
//		}
//		//f.copyTo(segm);
//		//cv::flip(segm, segm, 1);
//
//		//if (i > 0)
//		imshow("v窗口", frame);
//		i++;
//		sprintf_s(filename, "D:/OpencvCode/Project4/Project4/2/w%d.jpg", i);
//		c = waitKey(30);
//		imwrite(filename, frame);
//		if (c == 27) break;
//	}
//	cap.release();
//	return 1;
//
//}
//
//int main()
//{
//
//
//	int j = 0;
//	char c;
//	Mat img;
//	VideoWriter writer;
//
//	img = imread("D:/OpencvCode/Project4/Project4/2/w1.jpg");
//	bool isColor = (img.type() == CV_8UC3);
//	int code = VideoWriter::fourcc('M', 'J', 'P', 'G');
//
//
//	Mat cimg = imread("D:/OpencvCode/Project4/Project4/2/2.jpg");
//	resize(cimg, cimg, img.size(), 0, 0, 0);
//
//	double fps = 25.0;
//	writer.open("D:/OpencvCode/Project4/Project4/2/vi/out1.avi", code, fps, img.size(), isColor);
//
//	char filename[100];
//	char s[100];
//
//	namedWindow("v窗口", WINDOW_NORMAL);
//	namedWindow("v窗口", WINDOW_AUTOSIZE);
//	moveWindow("v窗口", 20, 20);
//	resizeWindow("v窗口", 512, 512);
//
//	for (j = 400; j > 2; j--)
//	{
//		sprintf_s(filename, "/OpencvCode/Project4/Project4/2/w%d.jpg", j);
//		img = imread(filename);
//		writer.write(img);
//
//
//		//sprintf_s(s, "moveint text page=%d", j);
//
//		if (j % 40 == 0)
//		{
//			for (int a = 0; a < 20; a++)
//				writer.write(cimg);
//			//putText(cimg, s, Point(1 + j, 100), 2, 1, Scalar(200, 200, 200));
//			imshow("v窗口", cimg);
//		}
//		else
//		{
//			//putText(img, s, Point(1 + j, 100), 2, 1, Scalar(200, 200, 200));
//			imshow("v窗口", img);
//		}
//
//
//
//		c = waitKey(100);
//		if (c == 27) break;
//
//	}/**/
//	return 1;
//
//}


