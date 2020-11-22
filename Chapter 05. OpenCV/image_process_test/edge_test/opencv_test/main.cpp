#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;

int main() {

	//edge ����
	// cvSobel(src, dst, x����, y����, Ŀ�� ������)
	// cvLaplace(src, dst, Ŀ�� ũ��): ��� ������ ���� ����
	IplImage* image = cvLoadImage("lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	IplImage* edgeImage = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);
	IplImage* laplaceImage = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);
	
	cvSobel(image, edgeImage, 1, 1, 3);
	cvLaplace(image, laplaceImage, 3);

	cvNamedWindow("original image");
	cvNamedWindow("edge image");
	cvNamedWindow("laplace image");

	cvShowImage("original image", image);
	cvShowImage("edge image", edgeImage);
	cvShowImage("laplace image", laplaceImage);

	cvWaitKey();

	cvDestroyAllWindows();

	cvReleaseImage(&image);
	cvReleaseImage(&edgeImage);
	cvReleaseImage(&laplaceImage);

	return 0;
}