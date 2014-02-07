#include <iostream>
#include <string>
#include "HSVFilter.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <thread>
#include <unistd.h>

using namespace cv;
using namespace std;

bool runtimeFeed = false;
bool camerafeed = false;

int displayFeedContinuously(){
        Mat feed;
        VideoCapture cap(0);
        if(!cap.isOpened()){
                
        }else{
        while(true){                    
                sleep(1);                
                cap.open(0);
                
                cap.read(feed);
                imshow("Feed", feed);
        }   
        }
}

int main(int argc, char *argv[]){
        
        //hue values for blue: 105 120
        //hue values for red: 160 180
        //hue values for green: 70 100

        //values to filter the Hue value
        int minHue = 70, maxHue = 100;
       
        //main Mat object
	Mat m;

        for(int i = 0; i < argc ; i++){

                //argument for the hue values when doing an inRange function
                if((string(argv[i])) == "-h"){
                        minHue = atoi(string(argv[i + 1]).c_str());
                        maxHue = atoi(string(argv[i + 2]).c_str());                       
                }

                //argument for getting the image from feed or command line argument
                 if((string(argv[i])) == "-c"){
                         //code to get the picture from camera feed
                         VideoCapture cap("rtsp://192.168.0.100/axis-media/media.amp");
                        camerafeed = true;
                         if(!cap.isOpened()){
                                wcout << "Unable to get camera";
                                return -1;    
                         }
        
                        m.release();
                        cap.read(m);
                }
                 
                 //argument to get the picture from a file
                 else if((string(argv[i])) == "-f"){
                        m = imread(argv[i + 1]);
                }
                       
        }
        if(runtimeFeed){
                thread runtimeFeedThread(displayFeedContinuously);
        
                runtimeFeedThread.join();
        }
        
        //check what properties it needs in order to be a mask
        //I think it has to be a binary image
        Mat greenFiltered;

        //HSV Filtering and histogram generation
        HSVFilter hFilter(m);
        
        hFilter.hueHistogram();

        Mat HSVImage = m.clone();

        Mat binImage = m.clone();
        
        //convert the color arrangement from RGB to HSV format
        cvtColor(HSVImage, HSVImage, CV_BGR2HSV);        
         
        //filter the image Hue              normally: 200
        inRange(HSVImage, Scalar(minHue, 0, 50), Scalar(maxHue, 255, 255), binImage);
        
        //save this code for general purposes
        Mat kernel = (Mat_<double>(5, 5) <<         
                        1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1
                        );
              
        
        //make sure that it is the right channel.
        kernel.convertTo(kernel, CV_8U);
            
        //reduces the noise
        erode(binImage, binImage, kernel);
        dilate(binImage, binImage, kernel);

        namedWindow("Original", 1);
        namedWindow("Ranged", 1);

        imshow( "Original", m);
        if(camerafeed){
                imwrite("FRC_CAMERA_IMAGE.png", m);
        }
	imshow("Ranged", binImage);
	waitKey(0);
        
        return 0;
}
