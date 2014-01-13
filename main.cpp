#include <iostream>
#include "HSVFilter.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>


using namespace cv;
using namespace std;

int main(int argc, char *argv[]){
        
        namedWindow("Original", 1);
               
	Mat m = imread(argv[1]);
	
        //GaussianBlur(m, m, Size(3, 3), .2, .2);
        
        //HSVFilter hFilter(m);
        
      //  hFilter.x = 150;
    //    hFilter.y = 130;        
  //      hFilter.width = 100;
//        hFilter.height = 100;

   //     hFilter.filter();
 //       hFilter.graph();
        
        Mat HSVImage = m.clone();

        Mat binImage = m.clone();
        
        cvtColor(m, HSVImage, CV_BGR2HSV);        

        inRange(HSVImage, Scalar(0, 0, 0), Scalar(360, 100, 100), binImage);

        //save this code for general purposes
        Mat kernel = (Mat_<double>(4, 4) <<         
                        1, 1, 1, 1,
                        1, 1, 1, 1,
                        1, 1, 1, 1
                        );
        
        kernel.convertTo(kernel, CV_8U);
        
        //Mat kernel = Mat::ones(4,4,CV_8U);
        
        //seperates all of the colors out 
       
        //reduces the noise
        erode(binImage, binImage, kernel);
        dilate(binImage, binImage, kernel);

        imshow( "Original", m);
	imshow("Ranged", binImage);
	waitKey(0);
        
        return 0;
}
