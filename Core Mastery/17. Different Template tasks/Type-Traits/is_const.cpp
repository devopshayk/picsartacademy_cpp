#include <iostream>

template <typename T>
struct is_const : std::false_type { };

template <typename T>
struct is_const<const T> : std::true_type { };


int main() {
    std::cout << is_const<int>::value << std::endl;
    std::cout << is_const<const int>::value << std::endl;

    return 0;
}