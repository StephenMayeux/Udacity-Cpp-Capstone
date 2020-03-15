# Mandelbrot Generator

## Project Description

This project creates beautiful Mandelbrot images and outputs them as PPM files. Because the PPM file format is supported across all platorms, no additional libaries are required to compile and run this project.

## How To Compile, Run, and Use

1. `g++ main.cpp mandelbrot.cpp` or `g++ *.cpp` to compile.
2. `./a.out` to execute the binary.
3. You will be prompted to enter 7 integers and doubles. The width and height of the image (intgers), the maximum number of iterations for the mandel brot set (integer) as well as the min/max values for the real and imaginary numbers needed to generate the mandelbrot (all floats).

For best results, start with these values and tweak the values in different ways to produce different results:

`512 512 255 -1.5 0.7 -1.0 1.0`

## File and Class Structure

This program is very simple and only contains three files. In `main.cpp` we gather the user's input in order to generate the mandelbrot and instantiate the Mandelbrot class. This class is defined in `mandelbrot.cpp` and `mandelbrot.h` and is responsible for initializing the private member variables, validating that the user input is valid, and producing the image.

## Rubric Points

1. The project demonstrates an understanding of C++ functions and control structures.

- In `mandelbrot.cpp` if statements on lines 7 and 12; for loops on lines 56 and 57. while loop on line 41. In additional, the logic is clearly organized into several private and public class methods.

2. The project reads data from an external file or writes data to a file as part of the necessary operation of the program.

- In `mandelbrot.cpp` the mandelbrot image is created on line 51 using `std::ofstream`.

3. The project accepts input from a user as part of the necessary operation of the program.

- In `main.cpp` user input is prompted on line 13 using `std::cin`.

4. The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.

- This is achieved in `mandelbrot.cpp` and `mandelbrot.h`

5. All class data members are explicitly specified as public, protected, or private.

- This is acheived in `mandelbrot.h`

6. All class members that are set to argument values are initialized through member initialization lists.

- This is achieved on line 3 in `mandelbrot.h`

7. All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.

- This is achieved through comments throughout `mandelbrot.cpp`

8. Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.

- This is acheived in ``mandelbrot.h` and invariants for image height and width are checked on line 5.

9. The project uses smart pointers instead of raw pointers.

- A unique pointer is used on line 15 in `main.cpp`