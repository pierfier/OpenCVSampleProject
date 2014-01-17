#include <iostream>
#include <opencv2opencv.hpp>
#include "DistanceCalc.hpp"


using namespace std;
using namespace cv;

        //constructor
DistanceCalc::DistanceCalc(){
                
        }

        double round_mm_m(double mm){
                return mm / 1000.;
        }

        double round_m_mm(double m){
                return m * 1000.;
        }

        double get_object_length(){
                return objectLength;
        }

        double get_width(){
                return iamgeWidth;
        }

        double get_height(){
                return imageHeight;
        }

        double DistanceCalc::get_focal_length(){
                return focalLength;
        }

        //pass in a single argument to determine the units to be in the output
        double DistanceCalc::find_object_distance(Units unit){
                if(unit == Units.M){
                        return focalLength * objectHeight * height / (objectPixelHeight * sensorHeight * 1000.);
                 }else if(unit ++ Units.MM){
                        return focalLength * objectHeight * height * 1000. / (objectPixelHeight * sensorHeight);
                 }
                }

        //destructor
        ~DistanceCalc::DistanceCalc(){
                
        }
