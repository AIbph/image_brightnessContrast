#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;

int main(int argc, char** argv){
	// ����ͼ�����ȺͶԱȶ�,g(i,j)=��f(i,j)+�£����������Աȶȣ� �£��������ȣ�

	// ����Mat����src��dest
	Mat src, dst;

	// ��ȡͼƬsrc
	src = imread("D:/OpenCVProject/day1210/����ͼ��ĶԱȶȺ�����/����ͼ��ĶԱȶȺ�����/thunder.jpg");

	// �ж�ͼƬ�Ƿ����
	if (!src.data)
	{
		printf("could not load image\n");
	}

	// չʾԭͼ
	char input_image[] = "origin image";
	namedWindow(input_image, CV_WINDOW_AUTOSIZE);
	imshow(input_image, src);
	
	// ����һ�ź�ԭͼ��Сһ����ȫ��ͼƬ
	dst = Mat::zeros(src.size(), src.type());

	// ������ͦ�
	float alpha = 1.2;
	float beta = 30;

	// ����convertTo��������dst��ֵ
	src.convertTo(dst, src.type(), alpha, beta);
	
	// ���ͼ��dst
	char output_image[] = "adjusted iamge";
	namedWindow(output_image, CV_WINDOW_AUTOSIZE);
	imshow(output_image, dst);

	
	waitKey(0);
	return 0;
}