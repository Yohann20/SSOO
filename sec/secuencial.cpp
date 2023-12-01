#include <iostream> 
#include <stdlib.h> 
#include <unistd.h>
#include <opencv2/opencv.hpp> 

using namespace cv; 
using namespace std; 

int main() {
    
    Mat image = imread("imagen.jpg", IMREAD_COLOR);
    if (image.empty()) {
        cout << "NO HAY IMAGEN" << endl;
        return -1;
    }

    Mat grayImage(image.rows, image.cols, CV_8UC1);
    
    for(int r=0; r<image.rows; r++) {
        for(int c=0; c<image.cols; c++) {
            Vec3b pixel = image.at<Vec3b>(r,c);
            uchar luminosity = 0.3*pixel[2] + 0.59*pixel[1] + 0.11*pixel[0];
            grayImage.at<uchar>(r,c) = luminosity;
        }
    }

    imwrite("imagen_en_gris.jpg", grayImage);

    return 0;
}