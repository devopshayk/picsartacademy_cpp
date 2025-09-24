#include <iostream>

    void print(int);
    void print(const int);

    int main() {
        int x{0};
        const int y{5};

        std::cout << "Write two numbers "
        << std::endl << std::endl;

        std::cout << "Int = ";
        std::cin >> x;

        std::cout << std::endl;

        std::cout << "Int = "; print(x);
        std::cout << "Const Int = "; print(y);

        return 0;
    }

    void print(int x) { std::cout << x << std::endl;}
    void print(const int y) {  std::cout << y << std::endl; } 

    // Redefinition error: for the compiler, a parameter of type int and const int (passed by value) are considered the same type.
    // Therefore, the compiler cannot distinguish between these two functions.