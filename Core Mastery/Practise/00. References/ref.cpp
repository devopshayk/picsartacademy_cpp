#include <iostream>

    int main() {
        int x{10};

        int &a = x, &b = x;

        a = 5;
        std::cout << b << std::endl;

        return 0;
    }