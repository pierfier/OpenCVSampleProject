#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]){
	
        namedWindow("Original", 1);
               
	Mat m = imread(argv[1]);
	Mat binImage = m.clone();
	
        //save this code for general purposes
        Mat kernel = (Mat_<double>(4, 4) <<         
                        1, 1, 1, 1,
                        1, 1, 1, 1,
                        1, 1, 1, 1
                        );
        
        kernel.convertTo(kernel, CV_8U);
        
        //Mat kernel = Mat::ones(4,4,CV_8U);
        
        //seperates all of the colors out 
        inRange(m, Scalar(20,50,0,0), Scalar(200 , 255, 100,255), binImage);
        
        //reduces the noise
        erode(binImage, binImage, kernel);
        dilate(binImage, binImage, kernel);
        
        imshow( "Original", m);
	imshow("Ranged", binImage);
	waitKey(0);
        
        return 0;
}
