#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char *argv[]){
	
	Mat m = imread(argv[1]);
	Mat binImage = m.clone();
	
        Mat kernel = (Mat_<double>(3,3) << 0,1 , 0, 1, 1, 1, 0, 1, 0);
        //seperates all of the colors out 
        inRange(m, Scalar(0,150,0,0), Scalar(200,255,200,255), binImage);
	
        erode(binImage, binImage, kernel);
        
        namedWindow("Original", 1);
	namedWindow("Ranged", 1);
	imshow( "Original", m);
	imshow("Ranged", binImage);
	waitKey(0);
        
        return 0;
}
