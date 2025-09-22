#include <iostream>

    int add(int, int);
    double add(double, double);

    int main() {
        int a{0}, b{0};

        std::cout << "Write two nums for sum: ";
        std::cin >> a >> b;

        std::cout << std::endl;

        int res1 = add(a, b);
        double res2 = add(a, b);

        std::cout << "Result1: " << res1 << std::endl;
        std::cout << "Result2: " << res2 << std::endl;

        return 0;
    }
    
    int add(int x, int y) {
        return x + y;
    }

    double add(double x, double y) {
        return x + y;
    }