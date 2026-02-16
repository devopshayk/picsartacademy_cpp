#include <iostream>
#include <string>


template<typename T>
T multiply(T a, T b) {
    return a * b;
}

template<>
int multiply<int>(int a, int b) {
    return a * b;
}

template<>
double multiply<double>(double a, double b) {
    double result = a * b;
    return result;
}

std::string multiply(std::string str, int count) {
    std::string newString{};

    for(int i{}; i < count; ++i) {
        newString += str;
    }
    
    return newString;
}


int main() {
    std::cout << multiply(5, 15) << std::endl;
    std::cout << multiply(5.0, 1.5) << std::endl;
    std::cout << multiply("Hayk", 3) << std::endl;

    return 0;
}