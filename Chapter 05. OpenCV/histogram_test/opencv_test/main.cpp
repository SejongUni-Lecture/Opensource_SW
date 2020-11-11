#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;

int main()
{
	IplImage* image = cvLoadImage("lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	IplImage* histoEqualImage = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);

	//1.히스토그램 생성
	//2.명암 누적 빈도수 계산
	//3.누적값 토대로 정규화

	cvEqualizeHist(image, histoEqualImage);
	
	cvNamedWindow("original image");
	cvNamedWindow("histogram equalized image");

	cvShowImage("original image", image);
	cvShowImage("histogram equalized image", image);
	
	cvWaitKey();

	cvDestroyAllWindows();
	cvReleaseImage(&image);
	cvReleaseImage(&histoEqualImage);

	return 0;
}