#include <iostream>
#include "mandelbrot.h"

int main() {
    std::cout << "Let\'s produce a mandelbrot!\n"
        << "You need to enter the following values, seperated by spaces:\n\n"
        << "image width (max 512), image height (512)\n"
        << "maxN, minR, maxR, minI, and maxI\n\n";
    
    int imageWidth, imageHeight, maxN;
    double minR, maxR, minI, maxI;
    std::cin >> imageWidth >> imageHeight >> maxN >> minR >> maxR >> minI >> maxI;

    Mandelbrot image(imageWidth, imageHeight, maxN, minR, maxR, minI, maxI);
    image.create_image();

    std::cout << "Finished!" << std::endl;
    return 0;
}