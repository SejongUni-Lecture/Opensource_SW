#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;

int main() {

	IplImage* image = cvLoadImage("lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	IplImage* maskImage = cvLoadImage("mask_image.png", CV_LOAD_IMAGE_GRAYSCALE);
	IplImage* cmpImage = cvLoadImage("compare.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	IplImage* andImage = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);
	IplImage* orImage = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);
	IplImage* xorImage = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);
	IplImage* notImage = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);

	cvAnd(image, maskImage, andImage);
	cvOr(image, maskImage, orImage);
	cvXor(image, cmpImage, xorImage);
	cvNot(image, notImage);

	cvNamedWindow("original image");
	cvNamedWindow("mask image");
	cvNamedWindow("compare image");
	cvNamedWindow("and image");
	cvNamedWindow("or image");
	cvNamedWindow("xor image");
	cvNamedWindow("not image");

	cvShowImage("original image", image);
	cvShowImage("mask image", maskImage);
	cvShowImage("compare image", cmpImage);
	cvShowImage("and image", andImage);
	cvShowImage("or image", orImage);
	cvShowImage("xor image", xorImage);
	cvShowImage("not image", notImage);

	cvWaitKey();

	cvDestroyAllWindows();

	cvReleaseImage(&image);
	cvReleaseImage(&maskImage);
	cvReleaseImage(&andImage);
	cvReleaseImage(&orImage);
	cvReleaseImage(&xorImage);

	return 0;
}