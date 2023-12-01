#include <omp.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]) { 

    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <num_hebras>" << endl;
        return -1;
    }

    int num_hebras = atoi(argv[1]);
    if (num_hebras <= 0) {
        cout << "El número de hebras debe ser mayor que 0." << endl;
        return -1;
    } 
    
    Mat image = imread("imagen2.jpg", IMREAD_COLOR);

    if (image.empty()) {
        cout << "NO HAY IMAGEN" << endl;
        return -1;
    } 

    Mat grayImage(image.rows, image.cols, CV_8UC1);

    #pragma omp parallel for num_threads(num_hebras)
    for (int r = 0; r < image.rows; r++) {
        for (int c = 0; c < image.cols; c++) {
            Vec3b pixel = image.at<Vec3b>(r, c);

            uchar luminosity = 0.3 * pixel[2] + 0.59 * pixel[1] + 0.11 * pixel[0];
            grayImage.at<uchar>(r, c) = luminosity;
        }
    }

    imwrite("imagen2_en_gris.jpg", grayImage);

    return 0;
}
