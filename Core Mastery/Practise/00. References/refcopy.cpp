#include <iostream>

    int main() {
        int x{5};

        int y = x;
        int& r = x;

        y = 10, r = 10;

        std::cout << "X = " << x << std::endl;
        std::cout << "Y = " << y << std::endl;
        std::cout << "R = " << r << std::endl;

        return 0;
    }