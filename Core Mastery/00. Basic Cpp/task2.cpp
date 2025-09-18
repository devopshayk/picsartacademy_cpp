#include <iostream>

    void swap(int& x, int& y);

    int main() {
        int a, b;
        
        std::cout << "Write two nums for swap: ";
        std::cin >> a >> b;

        std::cout << "Num 1 = " << a << ", Num 2 = " << b << std::endl;

        swap(a, b);

        std::cout << "Num 1 = " << a << ", Num 2 = " << b << std::endl;

        return 0;
    }

    void swap(int& x, int& y) {
        int tmp = x;
        x = y;
        y = tmp;
    }