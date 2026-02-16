#include <iostream>

template<typename T>
T&& my_forward(T& arg) {
    return static_cast<T&&>(arg);
}

void detect(int& x) {
    std::cout << "Lvalue: " << x << std::endl;
}

void detect(int&& x) {
    std::cout << "Rvalue: " << x << std::endl;
}

template<typename T>
void wrapper(T&& arg) {
    detect(my_forward<T>(arg));
}

int main() {
    int a = 42;
    wrapper(a);
    wrapper(100);
    return 0;
}