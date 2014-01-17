#include <iostream>
#include <string>
#include "HSVFilter.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]){

        //values to filter the Hue value
        int minHue = 70, maxHue = 100;

        for(int i = 0; i < argc ; i++){
                if((string(argv[i])) == "-h"){
                        minHue = atoi(string(argv[i + 1]).c_str());
                        maxHue = atoi(string(argv[i + 2]).c_str());                        
                }        
        }

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
 
        Mat HSVImage = m.clone();

        Mat binImage = m.clone();
        
        //convert the color arrangement from RGB to HSV format
        cvtColor(HSVImage, HSVImage, CV_BGR2HSV);        
        
        //filter the image Hue
        inRange(HSVImage, Scalar(minHue, 0, 0), Scalar(maxHue, 255, 255), binImage);

        //save this code for general purposes
        Mat kernel = (Mat_<double>(5, 5) <<         
                        1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1
                        );
              
        
        //make sure that it is the right channel.
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
