#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

#ifndef HSVFILTER_HPP
#define HSVFILTER_HPP

using namespace cv;

class HSVFilter{
        public:
                HSVFilter();
                ~HSVFilter();
                void filter();
                struct limit;

                //the Mat object that is being analyzed
                Mat mat;

                //pointer to the array
                int * distrPointer;

                //this will be the size of the Hue counter,
                //each element in array will have the number
                //of times the Hue would be seen
                int distribution[];

                //array length for pointer
                int length;
                                
};


#endif        
