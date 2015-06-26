#include <opencv/cv.h>
#include <opencv/cxcore.h> 
#include <opencv/highgui.h> 
#include <iostream>
using namespace std;
int main(int argc, char ** argv){
	CvCapture *cap = cvCreateCameraCapture(0);
	IplImage *image_detect;
	string cascade_name = "C:/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml";
	// Load cascade
	CvHaarClassifierCascade *classifier = (CvHaarClassifierCascade*)cvLoad(cascade_name.c_str(), 0, 0, 0);
	if (!classifier){
		cerr << "ERROR: Could not load classifier cascade." << endl;
		system("pause");
		return -1;
	}
	cvNamedWindow("Detect");
	while (1){
		image_detect = cvQueryFrame(cap);
		CvMemStorage *facesMemStorage = cvCreateMemStorage(0);
		IplImage *tempFrame = cvCreateImage(cvSize(image_detect->width, image_detect->height), IPL_DEPTH_8U, image_detect->nChannels);
		if (image_detect->origin == IPL_ORIGIN_TL){
			cvCopy(image_detect, tempFrame, 0);
		}
		else{
			cvFlip(image_detect, tempFrame, 0);
		}
		cvClearMemStorage(facesMemStorage);
		CvSeq* faces = cvHaarDetectObjects(tempFrame, classifier, facesMemStorage, 1.1, 3, CV_HAAR_DO_CANNY_PRUNING, cvSize(50, 50));
		if (faces){
			for (int i = 0; i < faces->total; ++i){
				// Setup two points that define the extremes of the rectangle,
				// then draw it to the image
				CvPoint point1, point2;
				CvRect* rectangle = (CvRect*)cvGetSeqElem(faces, i);
				point1.x = rectangle->x;
				point2.x = rectangle->x + rectangle->width;
				point1.y = rectangle->y;
				point2.y = rectangle->y + rectangle->height;
				cvRectangle(tempFrame, point1, point2, CV_RGB(255, 0, 0), 3, 8, 0);
			}
		}
		// Save the image to a file
		cvShowImage("Detect", tempFrame);
		// Clean up allocated OpenCV objects
		cvReleaseMemStorage(&facesMemStorage);
		cvReleaseImage(&tempFrame);
		int key = cvWaitKey(33);
		if (key == 27)
			break;
	}
	cvReleaseHaarClassifierCascade(&classifier);
	cvReleaseImage(&image_detect);
	return EXIT_SUCCESS;
}
