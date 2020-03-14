#include <fstream>
#include <iostream>
#include <random>

double mapToReal(int x, int imageWidth, double minR, double maxR) {
    double range = maxR - minR;
    return x * (range / imageWidth) + minR;
}

double mapToImaginary(int y, int imageHeight, double minI, double maxI) {
    double range = maxI - minI;
    return y * (range / imageHeight) + minI;
}

int findMandelbrot(double cr, double ci, int max) {
    int i = 0;
    double zr = 0.0, zi = 0.0;
    while (i < max && zr * zr + zi * zi < 4.0) {
        double temp = zr * zr - zi * zi + cr;
        zi = 2.0 * zr * zi + ci;
        zr = temp;
        i++;
    }
    return i;
}

int generateRandom() {
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> dist(0, 255);
    return dist(engine);
}

int main() {
    std::ifstream fileInput("params.txt");
    int imageWidth, imageHeight, maxN;
    double minR, maxR, minI, maxI;

    if (!fileInput) {
        std::cout << "Could not open file!" << std::endl;
        return 0;
    }

    fileInput >> imageWidth >> imageHeight >> maxN;
    fileInput >> minR >> maxR >> minI >> maxI;

    fileInput.close();

    std::ofstream fileOutput("output.ppm");
    fileOutput << "P3" << std::endl;
    fileOutput << imageWidth << " " << imageHeight << std::endl;
    fileOutput << "256" << std::endl;

    for (int y = 0; y < imageHeight; y++) {
        for (int x = 0; x < imageWidth; x++) {
            double cr = mapToReal(x, imageWidth, minR, maxR);
            double ci = mapToImaginary(y, imageHeight, minI, maxI);
            int n = findMandelbrot(cr, ci, maxN);

            int r = ((int)(n * sinf(n)) % 256);
            int g = ((n * n) % 256);
            int b = n % 256;

            fileOutput << r << " " << g << " " << b << " ";
        }
        fileOutput << std::endl;
    }
    fileOutput.close();
    std::cout << "Finished!" << std::endl;
    return 0;
}