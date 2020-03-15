#include <iostream>
#include <fstream>
#include <math.h>
#include "mandelbrot.h"

// Checks if user has entered a valid number for height and width
// If they do not, we set the height and width to 512 pixels
void Mandelbrot::verify_dimensions() {
    if (imageWidth_ < 256 || imageWidth_ > 512) {
        std::cout << "Image width invalid. Setting to 512" << std::endl;
        set_width();
    }

    if (imageHeight_ < 256 || imageHeight_ > 512) {
        std::cout << "Image height invalid. Setting to 512" << std::endl;
        set_height();
    }
}

bool Mandelbrot::set_width(int width) {
    imageWidth_ = width;
    return true;
}

bool Mandelbrot::set_height(int height) {
    imageHeight_ = height;
    return true;
}

// Takes the a coordinate and maps it to the real part of a set of complex numbers
// https://en.wikipedia.org/wiki/Mandelbrot_set for more information
double Mandelbrot::map_to_real(int x) {
    double range = maxR_ - minR_;
    return x * (range / imageWidth_) + minR_;
}

// Takes the a coordinate and maps it to the imaginary part of a set of complex numbers
// https://en.wikipedia.org/wiki/Mandelbrot_set for more information
double Mandelbrot::map_to_imaginary(int y) {
    double range = maxI_ - minI_;
    return y * (range / imageHeight_) + minI_;
}

// produces pattern based on maximum number of iterations of mandelbrot set
// https://en.wikipedia.org/wiki/Mandelbrot_set for more information
int Mandelbrot::find_mandelbrot(double cr, double ci) {
    int i = 0;
    double zr = 0.0, zi = 0.0;
    while (i < maxN_ && zr * zr + zi * zi < 4.0) {
        double temp = zr * zr - zi * zi + cr;
        zi = 2.0 * zr * zi + ci;
        zr = temp;
        i++;
    }
    return i;
}

void Mandelbrot::create_image() {
    std::ofstream fileOutput("output.ppm");
    fileOutput << "P3" << std::endl;
    fileOutput << imageWidth_ << " " << imageHeight_ << std::endl;
    fileOutput << "256" << std::endl;

    for (int y = 0; y < imageHeight_; y++) {
        for (int x = 0; x < imageWidth_; x++) {
            double cr = map_to_real(x);
            double ci = map_to_imaginary(y);
            int n = find_mandelbrot(cr, ci);

            // generate colors
            int r = ((int)(n * sinf(n)) % 256);
            int g = ((n * n) % 256);
            int b = n % 256;

            fileOutput << r << " " << g << " " << b << " ";
        }
        fileOutput << std::endl;
    }
    fileOutput.close();
}