/**
 * @function EqualizeHist_Demo.cpp
 * @brief Demo code for equalizeHist function
 * @author OpenCV team
**/

//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/imgproc.hpp"
//#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/**
 * @function main
 */

 int main(int argc, char** argv)
 {
	 //! [Load image]
	 CommandLineParser parser(argc, argv, "{@input | lena.jpg | input image}");
	 Mat src = imread(samples::findFile(parser.get<String>("@input")), IMREAD_COLOR);
	 if (src.empty())
	 {
		 cout << "Could not open or find the image!\n" << endl;
		 cout << "Usage: " << argv[0] << " <Input image>" << endl;
		 return -1;
	 }
	 //! [Load image]

	 //! [Convert to grayscale]
	 cvtColor(src, src, COLOR_BGR2GRAY);
	 //! [Convert to grayscale]

	 //! [Apply Histogram Equalization]
	 Mat dst;
	 equalizeHist(src, dst);
	 //! [Apply Histogram Equalization]

	 //! [Display results]
	 imshow("Source image", src);
	 imshow("Equalized Image", dst);
	 //! [Display results]

	 //! [Wait until user exits the program]
	 waitKey();
	 //! [Wait until user exits the program]

	 return 0;

 }

//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	Mat image = Mat::zeros(300, 600, CV_8UC3);
//	circle(image, Point(250, 150), 100, Scalar(0, 255, 128), -100);
//	circle(image, Point(350, 150), 100, Scalar(255, 255, 255), -100);
//	imshow("Display Window", image);
//	waitKey(0);
//	return 0;
//}