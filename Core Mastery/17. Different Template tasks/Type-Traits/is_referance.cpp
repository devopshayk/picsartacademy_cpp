#include <iostream>

template <typename T>
struct is_referance : std::false_type { };

template <typename T>
struct is_referance<T&> : std::true_type { };

template <typename T>
struct is_referance<T&&> : std::true_type { };


int main() {
    std::cout << is_referance<int>::value << std::endl;
    std::cout << is_referance<int&>::value << std::endl;
    std::cout << is_referance<int&&>::value << std::endl;

    return 0;
}