#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;

int main(int argc, char** argv){
	// 调整图像亮度和对比度,g(i,j)=αf(i,j)+β（α：调整对比度， β：调整亮度）

	// 定义Mat对象src和dest
	Mat src, dst;

	// 读取图片src
	src = imread("D:/OpenCVProject/day1210/调整图像的对比度和亮度/调整图像的对比度和亮度/thunder.jpg");

	// 判断图片是否存在
	if (!src.data)
	{
		printf("could not load image\n");
	}

	// 展示原图
	char input_image[] = "origin image";
	namedWindow(input_image, CV_WINDOW_AUTOSIZE);
	imshow(input_image, src);
	
	// 定义一张和原图大小一样的全黑图片
	dst = Mat::zeros(src.size(), src.type());

	// 定义α和β
	float alpha = 1.2;
	float beta = 30;

	// 调用convertTo方法，给dst赋值
	src.convertTo(dst, src.type(), alpha, beta);
	
	// 输出图像dst
	char output_image[] = "adjusted iamge";
	namedWindow(output_image, CV_WINDOW_AUTOSIZE);
	imshow(output_image, dst);

	
	waitKey(0);
	return 0;
}