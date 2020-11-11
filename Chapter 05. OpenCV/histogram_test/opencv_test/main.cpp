#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;

int main()
{
	IplImage* image = cvLoadImage("lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	IplImage* histoEqualImage = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);

	//1.������׷� ����
	//2.��� ���� �󵵼� ���
	//3.������ ���� ����ȭ

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