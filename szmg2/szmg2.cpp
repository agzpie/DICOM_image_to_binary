#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/photo.hpp>

using namespace cv;
using namespace std;

//BASIC VALUES
int thresholdValue = 0;
int thresholdType = 3;
int const maxValue = 255;
int const maxType = 4;

//TRACKBAR
const char* windowName = "Thresholded";
const char* trackbarType = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
const char* trackbarValue = "Value";

//GAUSSIAN BLUR
int adaptiveThresholdBlockSize = 3;
int adaptiveThresholdCValue = 1;
int adaptiveThresholdType = 0;
const char* binaryConvertionName = "ADAPTIVE_THRESH_GAUSSIAN_C";
const char* trackbarNameC = "C value";

//IMAGES
Mat src, sourceGrey, destination, denoised;

 void Threshold_Demo(int, void*)
 {
	/* 0: Binary
	 1: Binary Inverted
	 2: Threshold Truncated
	 3: Threshold to Zero
	 4: Threshold to Zero Inverted
	*/
	threshold(denoised, destination, thresholdValue, maxValue, thresholdType);
	imshow(windowName, destination);
 }
/* // GAUSSIAN BLUR
void adaptive_bar(int, void*)
{
	try
	{
		adaptiveThreshold(src, destination, maxValue, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, adaptiveThresholdBlockSize, adaptiveThresholdCValue);
		imshow(windowName, destination);
	}
	catch (Exception ex)
	{

	}
}
*/

/*
Mat MedianBlur(Mat& inputImage) {
	Mat outputImage;
	for (int i = 1; i < inputImage.rows; i = i + 2)
	{
		// Median smoothing
		medianBlur(inputImage, outputImage, i);
	}

	// show the blurred image with the text
	imshow("Median filter", outputImage);

	// wait
	waitKey();
	//return outputImage;
}*/


 int main(int argc, char** argv)
 {
	 // Loading image
	 CommandLineParser parser(argc, argv, "{@input | lena.jpg | input image}");
	 Mat src = imread(samples::findFile(parser.get<String>("@input")), IMREAD_COLOR);
	 if (src.empty())
	 {
		 cout << "Could not open or find the image!\n" << endl;
		 cout << "Usage: " << argv[0] << " <Input image>" << endl;
		 return -1;
	 }

	 //CONVERTING TO GREY
	 imshow("Original image", src);
	 cvtColor(src, sourceGrey, COLOR_BGR2GRAY);

	 //DENOISING
	 fastNlMeansDenoising(sourceGrey, denoised, 8, 7, 21);
	 imshow("Denoised", denoised);

	 //MEDIAN BLUR
	 //namedWindow(windowName, WINDOW_AUTOSIZE);	 
	 //createTrackbar(trackbarNameC, binaryConvertionName, &adaptiveThresholdBlockSize, maxType, adaptive_bar);
	 //createTrackbar(trackbarValue, binaryConvertionName, &adaptiveThresholdCValue, maxValue, adaptive_bar);
	 //MedianBlur(src);

	 //THRESHOLDING
	 namedWindow(windowName, WINDOW_AUTOSIZE); // Create a window to display results
	 createTrackbar(trackbarType, windowName, &thresholdType, maxType, Threshold_Demo); // Create a Trackbar to choose type of Threshold
	 createTrackbar(trackbarValue,	 windowName, &thresholdValue, maxValue, Threshold_Demo); // Create a Trackbar to choose Threshold value

	 Threshold_Demo(0, 0); // Call the function to initialize
	//adaptive_bar(0, 0);

	 waitKey();
	 return 0;
 }


