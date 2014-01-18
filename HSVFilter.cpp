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

                  upperHueLimit = 0;
                  lowerHueLimit = 0;
        }

        //needs to be implemented
        void HSVFilter::filterSaturation(){
                
        }

        void HSVFilter::graphSaturation(){
                
        }
        
        //needs to be implemented
        void HSVFilter::hueSaturationIntensityHisrogram(){
                 // Quantize the hue to 30 levels
                // and the saturation to 32 levels
                int hbins = 30, sbins = 32;
                int histSize[] = {hbins, sbins};
        // hue varies from 0 to 179, see cvtColor
       float hranges[] = { 0, 180 };
    // saturation varies from 0 (black-gray-white) to
    // 255 (pure spectrum color)
    float sranges[] = { 0, 256 };
    const float* ranges[] = { hranges, sranges };
    MatND hist;
    // we compute the histogram from the 0-th and 1-st channels
    int channels[] = {0, 1};

    calcHist( &mat, 1, channels, Mat(), // do not use mask
                             hist, 2, histSize, ranges,
                                      true, // the histogram is uniform
                                               false );
    double maxVal=0;
    minMaxLoc(hist, 0, &maxVal, 0, 0);

    int scale = 10;
    Mat histImg = Mat::zeros(sbins*scale, hbins*10, CV_8UC3);

    for( int h = 0; h < hbins; h++ )
        for( int s = 0; s < sbins; s++ ){
                float binVal = hist.at<float>(h, s);
                int intensity = cvRound(binVal);//*255/maxVal
                rectangle( histImg, Point(h*scale, s*scale),
                          Point( (h+1)*scale - 1, (s+1)*scale - 1),
                          Scalar::all(intensity),
                          CV_FILLED );
        }
        
        namedWindow("Histogram", 1);
        imshow("Histogram", histImg);
        
        }
        
        //implement this
        void HSVFilter::hueHistogram(){
                
        }

        
        int HSVFilter::getPixelHue(int xH, int yH){
                Vec3b pixel = mat.at<Vec3b>(yH, xH);
                return pixel[0];
        }

        int HSVFilter::getPixelSaturation(int xS, int yS){
                Vec3b pixel = mat.at<Vec3b>(yS, xS);
                return pixel[1];
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
                for(int i = lowerHueLimit; i < upperHueLimit; i++){
                        wcout << i << " ";
                        wcout << distribution[i];
                        wcout << endl;
                }
        }

        HSVFilter::~HSVFilter(){
                delete [] distribution;
        }
