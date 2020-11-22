#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;

int main() {

	IplImage* image = cvLoadImage("lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	IplImage* smoothImage = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);
	IplImage* gaussianImage = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);
	IplImage* medianImage = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);
	IplImage* bilateralImage = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);

	cvSmooth(image, smoothImage, CV_BLUR, 3); //커널 값은 항상 홀수이어야 한다
	cvSmooth(image, gaussianImage, CV_GAUSSIAN, 3);
	cvSmooth(image, medianImage, CV_MEDIAN, 3);
	cvSmooth(image, bilateralImage, CV_BILATERAL, 3);

	cvNamedWindow("original image");
	cvNamedWindow("smooth image");
	cvNamedWindow("gaussian image");
	cvNamedWindow("median image");
	cvNamedWindow("bilateral image");
	

	cvShowImage("original image", image);
	cvShowImage("smooth image", smoothImage);
	cvShowImage("gaussian image", gaussianImage);
	cvShowImage("median image", medianImage);
	cvShowImage("bilateral image", bilateralImage);

	cvWaitKey();

	cvDestroyAllWindows();

	cvReleaseImage(&image);
	cvReleaseImage(&smoothImage);

	return 0;
}