#include "HSVFilter.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

        using namespace cv;

        HSVFilter::HSVFilter(Mat m){
                distribution = new int[360];
                length = (sizeof distribution) / (sizeof int);
                distrPointer = distribution;

                mat = m;

                cvCvtColor(mat, mat, CV_BGR2HSV);
        }

        
        HSVFilter::limit{
                int HUpperLimit;
                int HLowerLimit;
        }

        void HSVFilter::filter(){
                        
        }

        HSVFitler::~HSVFilter(){
                
        }
