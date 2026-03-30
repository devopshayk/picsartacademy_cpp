#include <iostream>

template <typename T>
struct is_pointer : std::false_type { };

template <typename T>
struct is_pointer<T*> : std::true_type { };


int main() {
    std::cout << is_pointer<int>::value << std::endl;
    std::cout << is_pointer<int*>::value << std::endl;

    return 0;
}