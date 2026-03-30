#include <iostream>

template <typename T>
struct remove_const {
    using type = T;
};

template <typename T>
struct remove_const<const T> {
    using type = T;
};


int main() {
    std::cout << std::is_same<remove_const<int>::type, int>::value << std::endl;
    std::cout << std::is_same<remove_const<const int>::type, int>::value << std::endl;

    return 0;
}