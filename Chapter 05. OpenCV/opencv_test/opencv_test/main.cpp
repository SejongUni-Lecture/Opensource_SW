#include<opencv2\opencv.hpp>
#include<iostream>

using namespace std;

int main()
{
	IplImage* image = cvLoadImage("lena.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	IplImage* sumImage = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);
	IplImage* subImage = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);
	IplImage* mulImage = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);
	IplImage* divImage = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);
	

	//Summed image
	CvScalar pixelVal;
	pixelVal.val[0] = 100;		//gray scale의 channel 갯수는 한 가지 이므로
	cvAddS(image, pixelVal, sumImage);

	//Subtracted image
	pixelVal.val[0] = 50;
	cvSubS(image, pixelVal, subImage);

	//Multiplied image
	CvScalar tempScalar;
	double value = 0.0;

	for (int i = 0; i < image->height; i++)
	{
		for (int j = 0; j < image->width; j++)
		{
			tempScalar = cvGet2D(image, i, j);
			value = tempScalar.val[0] * 2.0;

			if (value > 255.0) 
			{
				pixelVal.val[0] = 255.0;
				cvSet2D(mulImage, i, j, pixelVal);
			}
			else
			{
				pixelVal.val[0] = value;
				cvSet2D(mulImage, i, j, pixelVal);
			}
		}
	}	//cvMul() 함수로도 사용 가능

	//Divided Image
	for (int i = 0; i < image->height; i++)
	{
		for (int j = 0; j < image->width; j++)
		{
			tempScalar = cvGet2D(image, i, j);
			value = tempScalar.val[0] / 3.0;
			
			pixelVal.val[0] = value;
			cvSet2D(divImage, i, j, pixelVal);
			
		}
	}	//cvMul() 함수로도 사용 가능


	cvNamedWindow("original image");
	cvShowImage("original image", image);

	cvNamedWindow("sum image");
	cvShowImage("sum image", sumImage);
	
	cvNamedWindow("sub image");
	cvShowImage("sub image", subImage);

	cvNamedWindow("mul image");
	cvShowImage("mul image", mulImage);

	cvNamedWindow("div image");
	cvShowImage("div image", divImage);


	cvWaitKey();

	cvDestroyAllWindows();
	cvReleaseImage(&image);
	cvReleaseImage(&sumImage);
	cvReleaseImage(&subImage);
	cvReleaseImage(&mulImage);
	cvReleaseImage(&divImage);

	return 0;
}