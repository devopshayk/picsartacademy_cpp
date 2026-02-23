#include <iostream>

template<typename... Arg>
double sum1(Arg... args) {
    return (... + args);
}

template<typename... Arg>
double sum2(Arg... args) {
    return (0 + ... + args);
}


int main() {
    auto v1 = sum1(2, 3.4, 14.9f); // Version 1
    auto v2 = sum2(2, 3.4, 14.9f); // Version 2

    std::cout << "Version 1: " << v1 << std::endl;
    std::cout << "Version 2: " << v2 << std::endl;

    return 0;
}