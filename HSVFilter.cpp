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
        
        void HSVFilter::valueHistogram(){
                
        }

        //TODO provide a mask to have only the green hue values!!!!
        //then do the same thing for the value histogram
        //it would be preferred to do a Gaussian Blur, so there are a minimal amount of variation in the Hue values
        
        void HSVFilter::hueHistogram(){

                //clones the objects Mat object to the methods disposal
                Mat image = mat.clone();
 
                //blur the image, this allows for distinct differences in Hue color values
                GaussianBlur(image, image, Size(3, 3), 1.0);
                
                cvtColor(image, image, CV_HSV2BGR);
                
                imshow("Blur", image);
                
                cvtColor(image, image, CV_BGR2HSV);
               
                //Mat object that is going to be used for the masking
                
                Mat mask = image.clone();

                inRange(mask, Scalar(70, 0, 0), Scalar(100, 255, 255), mask);
                
                imshow("Masking", mask);

                int histSize = 100;
                float vRange[] = {0, 180};
                const float* range[] = {vRange};
                int channel[] = {0};
                Mat histResult;

                //calculate the histogram and sets it equal to histResult
                calcHist( &image, 1, channel, mask, histResult, 1, &histSize, range, true, false );
                
                //normalizes the histogram
               
                int bin_w = cvRound( (double) 500 / histSize);
                
                //the object that actually has the plotted data
                Mat histogram(400, 500, CV_8UC3, Scalar( 0,0,0));
               
                normalize(image, image, 0, histogram.rows, NORM_MINMAX, -1, Mat() );
 
                //draws the histogram plot to the histogram image
                for(int i = 1; i < histSize; i++){
                        line(histogram, Point( bin_w * (i - 1), 400 -  cvRound(histResult.at<float>(i - 1)) ), Point( bin_w * (i), 400 - cvRound(histResult.at<float>(i)) ),
                                        Scalar(100, 200, 0), 2, 8, 0 
                                        );
                }

                namedWindow("Histogram", 1);
                imshow("Histogram", histogram);
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
