#include <iostream>

template <class T, class U>
struct is_same : std::false_type { };

template <typename T>
struct is_same<T, T> : std::true_type { };


int main() {
    std::cout << is_same<int, float>::value << std::endl;
    std::cout << is_same<int, int>::value << std::endl;

    return 0;
}