#include <iostream>

template <typename T>
struct add_referance {
    using type = T&;
};


int main() {
    std::cout << std::is_same<add_referance<int>::type, int&>::value << std::endl;
    std::cout << std::is_same<add_referance<int&>::type, int&>::value << std::endl;
    std::cout << std::is_same<add_referance<int&&>::type, int&>::value << std::endl;

    return 0;
}