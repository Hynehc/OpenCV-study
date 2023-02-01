#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#define TEST_RGB 0;//0��ʹ�ûҶ�ͼ������ʾ	1.ʹ��RGBͼ������ʾ
#define GAMMA_FACTOR 0.5;//gamma������gammaֵ
int gammaCorrection(cv::Mat srcMat, cv::Mat& dstMat, float gamma)
{

	//������ֻ����ͨ��ͼ��
	if (srcMat.channels() != 1)return -1;

	//������ѯ��
	unsigned char lut[256];
	for (int i = 0; i < 256; i++)
	{
		//saturate_cast����ֹ����ֵ��������ֵ<0,�򷵻�0���������255���򷵻�255
		lut[i] = saturate_cast<uchar>(pow((float)(i / 255.0f), gamma) * 255.0f);
	}

	srcMat.copyTo(dstMat);

	MatIterator_<uchar> it, end;
	for (it = dstMat.begin<uchar>(), end = dstMat.end<uchar>(); it != end; it++) {
		*it = lut[(*it)];
	}

	return 0;
}

int drawIntenHist(cv::Mat& histMat, float* srcHist, int bin_width, int bin_heght)
{
	histMat.create(bin_heght, 256 * bin_width, CV_8UC3);
	histMat = Scalar(255, 255, 255);

	float maxVal = *std::max_element(srcHist, srcHist + 256);

	for (int i = 0; i < 256; i++) {
		Rect binRect;
		binRect.x = i * bin_width;
		float height_i = (float)bin_heght * srcHist[i] / maxVal;
		binRect.height = (int)height_i;
		binRect.y = bin_heght - binRect.height;
		binRect.width = bin_width;
		rectangle(histMat, binRect, CV_RGB(255, 0, 0), -1);
	}

	return 0;
}

int calcIntenHist(const cv::Mat src, float* dstHist)
{

	//�����Ϊ��ͨ��ͼ
	if (src.type() != CV_8UC1) {
		return -1;
	}

	memset(dstHist, 0, sizeof(float) * 256);
	int height = src.rows;
	int width = src.cols;
	//ָ�����
	for (int k = 0; k < height; k++)
	{
		// ��ȡ��k�е��׵�ַ
		const uchar* inData = src.ptr<uchar>(k);
		//����ÿ������
		for (int i = 0; i < width; i++)
		{
			int gray = inData[i];
			dstHist[gray]++;
		}
	}

	//ֱ��ͼ��һ��
	float norm = height * width;
	for (int n = 0; n < 256; n++) {
		dstHist[n] = dstHist[n] / norm;
	}


	return 0;
}
int gammaMain()
{

	cout << "gamma correction demo" << endl;

	int readType = TEST_RGB;
	cv::Mat srcMat;

	//�������Ƿ�Ϸ�
	if (readType == 0) {
		srcMat = imread("girl.png", 0);
	}
	else if (readType == 1) {
		srcMat = imread("girl.png");
	}
	else {
		cout << "parameter erroe!" << endl;
		return -1;
	}

	if (srcMat.empty()) {
		cout << "fail to read pic!" << endl;
		return -1;
	}

	cv::Mat dstMat;
	float gamma = GAMMA_FACTOR;

	if (srcMat.type() == CV_8UC1) {

		gammaCorrection(srcMat, dstMat, gamma);

	}
	else if (srcMat.type() == CV_8UC3) {
		Mat channel[3];
		Mat out[3];
		float hist[3][256];

		//ͨ������
		split(srcMat, channel);

		for (int i = 0; i < 3; i++) {

			gammaCorrection(channel[i], out[i], gamma);
		}

		merge(out, 3, dstMat);

	}


	imshow("src", srcMat);
	imshow("dst", dstMat);
	waitKey(0);

	destroyAllWindows();

	return 0;
}

int equalizeMain()
{

	cout << "Histogram equalization demo" << endl;

	int readType = TEST_RGB;
	cv::Mat srcMat;

	//�������Ƿ�Ϸ�
	if (readType == 0) {
		srcMat = imread("girl.png", 0);
	}
	else if (readType == 1) {
		srcMat = imread("girl.png");
	}
	else {
		return -1;
	}

	if (srcMat.empty()) {
		cout << "fail to read pic!" << endl;
		return -1;
	}
	cv::Mat dstMat;
	cv::Mat dstHistMat;
	cv::Mat srcHistMat;
	cv::Mat histMat[3];

	float srcHist[256];
	float dstHist[256];

	int bin_width = 2;
	int bin_heigth = 100;

	//0.����ͼ�������� 8λ��ͨ��
	//1.���ͼ��������ͬ���ߴ�ͬ������
	if (srcMat.type() == CV_8UC1) {

		equalizeHist(srcMat, dstMat);

		//���㲢����ֱ��ͼ
		calcIntenHist(dstMat, dstHist);
		drawIntenHist(dstHistMat, dstHist, 3, 100);
		imshow("dstMat", dstMat);
		imshow("dstMat hist", dstHistMat);

		calcIntenHist(srcMat, srcHist);
		drawIntenHist(srcHistMat, srcHist, 3, 100);

		imshow("srcMat hist", srcHistMat);
		imshow("srcMat", srcMat);

	}
	else if (srcMat.type() == CV_8UC3) {
		Mat channel[3];
		Mat out[3];
		float hist[3][256];

		//ͨ������
		split(srcMat, channel);

		for (int i = 0; i < 3; i++) {
			equalizeHist(channel[i], out[i]);
			calcIntenHist(out[i], hist[i]);
			drawIntenHist(histMat[i], hist[i], bin_width, bin_heigth);

			//����channel�����������
			stringstream ss;
			ss << i;
			string histWindow = "Hist of chanel " + ss.str();
			string matWindow = "Image of chanel " + ss.str();

			imshow(histWindow, histMat[i]);
			imshow(matWindow, out[i]);

		}

		merge(out, 3, dstMat);

		//ԭͼת��λ�Ҷ�ͼ��������Ҷ�ֱ��ͼ
		cv::Mat grayMat;
		cv::Mat graydstMat;
		cvtColor(srcMat, grayMat, COLOR_BGR2GRAY);
		cvtColor(dstMat, graydstMat, COLOR_BGR2GRAY);

		//���㲢����ֱ��ͼ
		calcIntenHist(graydstMat, dstHist);
		drawIntenHist(dstHistMat, dstHist, 3, 100);
		imshow("dstMat", dstMat);
		imshow("dstMat hist", dstHistMat);

		calcIntenHist(grayMat, srcHist);
		drawIntenHist(srcHistMat, srcHist, 3, 100);

		imshow("srcMat hist", srcHistMat);
		imshow("srcMat", srcMat);

	}


	waitKey(0);

	destroyAllWindows();

	return 0;

}


int main()
{
	//gammaMain();
	equalizeMain();
	return 0;
}