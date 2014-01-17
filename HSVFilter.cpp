#include <iostream>
#include "HSVFilter.hpp"
#include <opencv2/opencv.hpp>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

        using namespace std;
        using namespace cv;

        HSVFilter::HSVFilter(Mat m){
                length = sizeof distribution / (sizeof (int));
                
                distribution = new int[360];

                for(int i = 0; i < length; i++){
                        distribution[i] = 0;
                }
                
                x = 0;
                y = 0;
                
                mat = m.clone();

                width = mat.rows;
                height = mat.cols;
               
                cvtColor(mat, mat, CV_BGR2HSV);

                  limit.upperLimit = 0;
                  limit.lowerLimit = 0;
        }

        void HSVFilter::filterSaturation(){
                
        }

        void HSVFilter::graphSaturation(){
                
        }
        
        int HSVFilter::getPixelHue(int xH, int yH){
                Vec3b pixel = mat.at<Vec3b>(yH, xH);
                return pixel[0];
        }

        int HSVFilter::getPixelSaturation(int xS, int yS){
                Vec3b pixel = mat.at<Vec3b>(yS, xS);
        }

        void HSVFilter::filterHue(){
                
                for(int i = x; i < width; i++){
                        for(int j = y; j < height; j++){
                                Vec3b pixel = mat.at<Vec3b>(i, j);
                                wcout << "Pixel's Hue: " << i << " " << j << " " << pixel[0] << endl;
                                distribution[pixel[0]] += 1;
                        }
                }
        }

        void HSVFilter::graphHue(){
                for(int i = hueLimit.lowerLimit; i < hueLimit.upperLimit; i++){
                        wcout << i << " ";
                        wcout << distribution[i];
                        wcout << endl;
                }
        }

        HSVFilter::~HSVFilter(){
                delete [] distribution;
        }
