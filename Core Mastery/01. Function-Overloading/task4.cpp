#include <iostream>

    double area(double radius);
    int area(int width, int height);
    double area(double base, double height);

    int main() {
        double r = 5.0;
        int w = 6, h = 4;
        double b = 3.0, h_g = 7.0;

        std::cout << "Area of circle (r = " << r << ") = " << area(r) << std::endl;
        std::cout << "Area of rectangle (" << w << " x " << h << ") = " << area(w, h) << std::endl;
        std::cout << "Area of triangle (base = " << b << ", height = " << h_g << ") = " << area(b, h_g) << std::endl;
    
        return 0;
    }

    double area(double radius) {
        double PI = 3.14;
        return PI * radius * radius;
    }

    int area(int width, int height) {
        return width * height;
    }

    double area(double base, double height) {
        return 0.5 * base * height;
    }