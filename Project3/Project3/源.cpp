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
//������������
void drawMyContours(string winName, Mat& image, vector<vector<Point>>contours, bool draw_on_blank)
{
	Mat temp;
	if (draw_on_blank)// �ڰ׵��ϻ�������
	{
		temp = Mat(image.size(), CV_8U, Scalar(255));
		drawContours(
			temp,
			contours,
			-1,//��ȫ������
			0, //�ú�ɫ��
			2);//���
	}
	else// ��ԭͼ�ϻ�������
	{
		temp = image.clone();
		drawContours(
			temp,
			contours,
			-1,//��ȫ������
			Scalar(0,100,0),
			2);//���
	}
	//imshow(winName, temp);
	waitKey();
}
void slove_blue()
{
	// ȥ��
	GaussianBlur(src, src, Size(3, 3), 1);
	//��ֵ��
	Mat blue;
	inRange(src, Scalar(80, 0, 0), Scalar(255, 85, 85), blue);
	//imshow("b", blue);

	//3.��������
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	findContours(blue, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
	printf("find %lld contours", contours.size());

	//4.��������
	drawMyContours("contours", src, contours, true);

	// 5.ɸѡ����
	// ��ʼ��������
	vector<vector<Point>>::iterator itc = contours.begin();
	vector<Vec4i>::iterator itc_hierarchy = hierarchy.begin();
	//ʹ�ò㼶�ṹɸѡ����
	int i = 0;
	while (itc_hierarchy != hierarchy.end())
	{
		//��֤������С
		if (hierarchy[i][3] > 0)// ����������/������
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
	// ���Ƽ���ɸѡ�������
	drawMyContours("contours after hierarchy filtering", src, contours, true);

	// ʹ�����������˲�
	// �����������
	itc = contours.begin();
	itc_hierarchy = hierarchy.begin();
	while (itc != contours.end())
	{
		//��֤������С
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
	// ���Ƴ���ɸѡ�������
	drawMyContours("1contours after length filtering", src, contours, true);


	// 6.��״������
	// ��С���Ǿ���
	Mat result = src.clone();
	Rect rect1 = boundingRect(contours[0]);
	Rect rect2 = boundingRect(contours[1]);
	rectangle(result, rect1, Scalar(0, 255, 0), 1);
	rectangle(result, rect2, Scalar(0, 255, 0), 1);

	// 7.���������أ�������
	itc = contours.begin();
	while (itc != contours.end())
	{
		// ����ȫ��������
		Moments mom = moments(Mat(*itc++));
		// ������
		Point pt = Point(mom.m10 / mom.m00, mom.m01 / mom.m00);//ʹ��ǰ������m00, m01��m10��������
		circle(result, pt, 2, (0, 0, 0), 2);
		// ��ע��������ֵ
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
	// ȥ��
	GaussianBlur(src, src, Size(3, 3), 1);
	//��ֵ��
	Mat red;
	inRange(src, Scalar(0, 0, 80), Scalar(85, 85, 255), red);
	//imshow("r", red);

	//3.��������
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	findContours(red, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
	printf("find %lld contours", contours.size());

	//4.��������
	drawMyContours("contours", src, contours, true);

	// 5.ɸѡ����
	// ��ʼ��������
	vector<vector<Point>>::iterator itc = contours.begin();
	vector<Vec4i>::iterator itc_hierarchy = hierarchy.begin();
	//ʹ�ò㼶�ṹɸѡ����
	int i = 0;
	while (itc_hierarchy != hierarchy.end())
	{
		//��֤������С
		if (hierarchy[i][3] > 0)// ����������/������
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
	// ���Ƽ���ɸѡ�������
	drawMyContours("contours after hierarchy filtering", src, contours, true);

	// ʹ�����������˲�
	// �����������
	itc = contours.begin();
	itc_hierarchy = hierarchy.begin();
	while (itc != contours.end())
	{
		//��֤������С
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
	// ���Ƴ���ɸѡ�������
	drawMyContours("1contours after length filtering", src, contours, true);


	// 6.��״������
	// ��С���Ǿ���
	Mat result = ss.clone();
	Rect rect1 = boundingRect(contours[0]);
	Rect rect2 = boundingRect(contours[1]);
	Rect rect3 = boundingRect(contours[2]);
	rectangle(result, rect1, Scalar(0, 255, 0), 1);
	rectangle(result, rect2, Scalar(0, 255, 0), 1);
	rectangle(result, rect3, Scalar(0, 255, 0), 1);

	// 7.���������أ�������
	itc = contours.begin();
	while (itc != contours.end())
	{
		// ����ȫ��������
		Moments mom = moments(Mat(*itc++));
		// ������
		Point pt = Point(mom.m10 / mom.m00, mom.m01 / mom.m00);//ʹ��ǰ������m00, m01��m10��������
		circle(result, pt, 2, (0, 0, 0), 2);
		// ��ע��������ֵ
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

