#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main()
{
	IplImage* image = cvLoadImage("lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	IplImage* bgImage = cvLoadImage("bgimage.png", CV_LOAD_IMAGE_GRAYSCALE);
	IplImage* resultImage = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);
	
	cvAddWeighted(image, 0.9, bgImage, 0.4, 0, resultImage);

	cvNamedWindow("original image");
	cvNamedWindow("background image");
	cvNamedWindow("result image");

	cvShowImage("original image", image);
	cvShowImage("background image", bgImage);
	cvShowImage("result image", resultImage);
	
	cvWaitKey();

	cvDestroyAllWindows();

	cvReleaseImage(&image);
	cvReleaseImage(&bgImage);
	cvReleaseImage(&resultImage);


	return 0;
}