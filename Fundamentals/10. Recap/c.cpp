#include <iostream>

int main() {
    auto x{2};
    auto y = {2};

    int z = 5;

    std::cout << typeid(x).name() << std::endl;
    std::cout << typeid(z).name() << std::endl;
    std::cout << typeid(y).name();
}