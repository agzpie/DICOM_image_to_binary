#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
//#include <dcmtk>

using namespace cv;
using namespace std;



Mat equalizeIntensity(const Mat& inputImage)
{
	if (inputImage.channels() >= 3)
	{
		Mat ycrcb;

		imshow("Before", inputImage);

		cvtColor(inputImage, ycrcb, COLOR_BGR2YCrCb);

		vector<Mat> channels;

		split(ycrcb, channels);

		equalizeHist(channels[0], channels[0]);

		Mat result;

		merge(channels, ycrcb);

		cvtColor(ycrcb, result, COLOR_YCrCb2BGR);
		
		imshow("YCrCb equalization", result);

		waitKey();
	}
	return Mat();
}


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

	 Mat gray;

	 equalizeIntensity(src);

	 waitKey();


	 /*
	 DicomImage* image = new DicomImage("test.dcm");
	 if (image != NULL)
	 {
		 if (image->getStatus() == EIS_Normal)
		 {
			 if (image->isMonochrome())
			 {
				 image->setMinMaxWindow();
				 Uint8* pixelData = (Uint8*)(image->getOutputData(8 /* bits ));
				 if (pixelData != NULL)
				 {
					 /* do something useful with the pixel data 
				 }
			 }
		 }
		 else
			 cerr << "Error: cannot load DICOM image (" << DicomImage::getString(image->getStatus()) << ")" << endl;
	 }
	 delete image;
	 */

	 return 0;
 }