#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;

int main() {

	// 배경에서 부터 객체 추출
	IplImage* grayFrame = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage* bgImage = cvCreateImage(cvGetSize(grayFrame), IPL_DEPTH_8U, 1);
	IplImage* resultImage = cvCreateImage(cvGetSize(grayFrame), IPL_DEPTH_8U, 1);

	CvCapture* capture = cvCaptureFromFile("test.avi");
	
	bool isBackGround = false;

	while (capture) {

		cvGrabFrame(capture);
		IplImage* frame = cvRetrieveFrame(capture);

		if (!frame) break;

		cvShowImage("original video", frame);
		
		cvCvtColor(frame, grayFrame, CV_BGR2GRAY);
		cvShowImage("gray video", grayFrame);

		if (isBackGround == false) {
			cvCopy(grayFrame, bgImage);
			isBackGround = true;
		}

		cvShowImage("background image", bgImage);

		cvSub(grayFrame, bgImage, resultImage);
		cvShowImage("result video", resultImage);

		if (cvWaitKey(33) == 27) break;
	}

	cvReleaseCapture(&capture);
	cvReleaseImage(&grayFrame);
	cvReleaseImage(&bgImage);
	cvReleaseImage(&resultImage);
	cvDestroyAllWindows();

	return 0;
}