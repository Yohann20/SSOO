#include <iostream> 
#include <opencv2/opencv.hpp> 
#include <chrono>

using namespace cv; 
using namespace std; 

int main(int argc, char * argv[]) {
    

    string Imagen = argv[1];
    string ImagenSalida = argv[2];

    Mat image = imread(Imagen, IMREAD_COLOR);
    
    if (image.empty()) {
        cout << "NO HAY IMAGEN" << endl;
        return -1;
    }

    Mat grayImage(image.rows, image.cols, CV_8UC1);
    auto start = chrono::high_resolution_clock::now(); 
    
    for(int r=0; r<image.rows; r++) {
        for(int c=0; c<image.cols; c++) {
            Vec3b pixel = image.at<Vec3b>(r,c);
            uchar luminosity = 0.3*pixel[2] + 0.59*pixel[1] + 0.11*pixel[0];
            grayImage.at<uchar>(r,c) = luminosity;
        }
    } 

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout << "Tiempo de ejecución: " << duration.count() << " milisegundos" << endl;

    imwrite(ImagenSalida, grayImage);

    return 0;
}
