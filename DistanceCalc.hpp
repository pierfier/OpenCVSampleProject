#include <opencv2/opencv.hpp>

#ifndef DistanceCalc_HPP
#define DistanceCalc_HPP

//measurement is in mm
#define AXIS_M1013_FOCAL_LENGTH  2.8

using namespace cv;

//all the measurements will be done in mm
//the conversion is easy though, there will be a conversion
//function
class DistanceCalc{
        public:
                DistanceCalc();
                ~DistanceCalc();
          
                double round_mm_m(double mm);
                double round_m_mm(double m);      
                double get_focal_length();
                double get_object_length();
                double get_width();
                double get_height();
                double find_object_distance(Units unit);
                
                //declare enum type
                static enum Units{
                        MM, M
                };

        private:
                //focal length of camera
                double focalLength;
                
                //specified object length
                double objectLength;

                //image height and width
                double imageWidth;
                double imageHeight;

                //the actual height of the object
                double objectWidth;
                double objectheight;

                //the height of the object within the image
                double objectPixelWidth;
                double objectPixelHeight;

                //the sensor height
                double sensorLength;              

};

#endif
