#include <iostream>
#include "HSVFilter.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]){
        int minHue = 40, maxHue = 100;

        namedWindow("Original", 1);
        namedWindow("Ranged", 1);

	Mat m = imread(argv[1]);
        
        wcout << "Number of channels in image: " <<m.channels() << endl;        
        
        //GaussianBlur(m, m, Size(3, 3), .2, .2);
        
        HSVFilter hFilter(m);
        
        hFilter.x = 168;
        hFilter.y = 161;

   //     hFilter.filter();
 //       hFilter.graph();
        wcout << "Hue Value: " << hFilter.getPixelHue() << endl;

        Mat HSVImage = m.clone();

        Mat binImage = m.clone();
        
        cvtColor(HSVImage, HSVImage, CV_BGR2HSV);        
        
        inRange(HSVImage, Scalar(minHue, 0, 0), Scalar(maxHue, 255, 255), binImage);

        //save this code for general purposes
        Mat kernel = (Mat_<double>(4, 4) <<         
                        1, 1, 1, 1,
                        1, 1, 1, 1,
                        1, 1, 1, 1
                        );
        
        kernel.convertTo(kernel, CV_8U);
        
 //       Mat kernel = Mat::ones(4,4,CV_8U);
        
        //seperates all of the colors out 
       
        //reduces the noise
        erode(binImage, binImage, kernel);
        dilate(binImage, binImage, kernel);

        imshow( "Original", m);
	imshow("Ranged", binImage);
	waitKey(0);
        
        return 0;
}
