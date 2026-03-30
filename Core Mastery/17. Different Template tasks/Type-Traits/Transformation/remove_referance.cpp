#include <iostream>

template <typename T>
struct rem_ref {
    using type = T;
};

template <typename T>
struct rem_ref<T&> {
    using type = T;
};

template <typename T>
struct rem_ref<T&&> {
    using type = T;
};


int main() {
    std::cout << std::is_same<rem_ref<int>::type, int>::value;
    std::cout << std::is_same<rem_ref<int&>::type, int>::value;
    std::cout << std::is_same<rem_ref<int&&>::type, int>::value;

    return 0;
}