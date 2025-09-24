#include <iostream>

    void print(int a) {
        std::cout << a << std::endl;
    }

    void print(float b) {
        std::cout << b << std::endl;
    }

    void print(double c) {
        std::cout << c << std::endl;
    }

    int main() {
        int a{0};
        float b{0.0f};
        double c{0.0};

        std::cout << "Write three numbers for print\n\n";

        std::cout << "Write the type int: ";
        std::cin >> a;

        std::cout << "Write the type float: ";
        std::cin >> b;

        std::cout << "Write the type double: ";
        std::cin >> c;

        std::cout << "Int = ";    print(a);
        std::cout << "Float = ";  print(b);
        std::cout << "Double = "; print(c);

        return 0;
    }
