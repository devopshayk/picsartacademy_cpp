#include <iostream>

    void print(int&);
    void print(const int&);

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

    void print(int& x) { std::cout << x << std::endl;}
    void print(const int& y) {  std::cout << y << std::endl; } 

    // This example demonstrates function overloading with references:
    // - print(int&)       — accepts a mutable int
    // - print(const int&) — accepts a const int or any int that cannot be modified through this reference

    // Difference from overloading by value:
    // If the parameters were just int and const int (by value), overloading would be impossible,
    // because the compiler treats them as the same type.
    // With references, const becomes part of the type, so overloading works.
    // Also, const int& allows passing const objects and temporary values.