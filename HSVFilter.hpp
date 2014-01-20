#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

#ifndef HSVFILTER_HPP
#define HSVFILTER_HPP

using namespace cv;

class HSVFilter{
        public:
                HSVFilter(Mat m);
                ~HSVFilter();

                void filterHue();
                void graphHue();
                void filterSaturation();
                void graphSaturation();
                void hueHistogram();
                void hueSaturationIntensityHisrogram();
                

                //methods to get specific pixel attributes
                int getPixelHue(int x, int y);
                int getPixelSaturation(int x, int y);
                
                //the minimal Hue value that is in between the two peaks
                int hueMinimal;

                        double upperHueLimit;
                        double lowerHueLimit;
                
                //the Mat object that is being analyzed
                Mat mat;

                //this will be the size of the Hue counter,
                //each element in array will have the number
                //of times the Hue would be seen
                int* distribution;

                //the bounds for checking a region
                int x;
                int y;
                int width;
                int height;

                //array length for pointer
                int length;
                                
};


#endif        
