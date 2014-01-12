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
                
                for(int i = 0; i < length; i++){
                        distribution[i] = 0;
                }
                
                x = 0;
                y = 0;
                
                width = mat.rows;
                height = mat.cols;

                wcout << width << " " << height;
        
                mat = m.clone();

                cvtColor(mat, mat, CV_BGR2HSV);
                  limit.upperLimit = 0;
                  limit.lowerLimit = 0;
        }

        void HSVFilter::filter(){
                
                for(int i = x; i < width; i++){
                        for(int j = y; j < height; j++){
                                Vec3b pixel = mat.at<Vec3b>(i, j);
                                wcout << "Pixel's Hue: " << i << " " << j << " " << pixel[0] << endl;
                                distribution[pixel[0]] += 1;
                        }
                }
        }

        void HSVFilter::graph(){
                for(int i = 0; i < length; i++){
                        wcout << i << " ";
                        wcout << distribution[i];
                        wcout << endl;
                }
        }

        HSVFilter::~HSVFilter(){
                delete [] distribution;
        }
