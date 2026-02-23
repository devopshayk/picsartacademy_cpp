#include <iostream>

template<typename... Arg>
int countArgs1(Arg... args) {
        size_t arg_count = sizeof...(args);

        return arg_count;
}

template<typename... Arg>
int countArgs2(Arg... args) {
    return  countArgs1(args...);
}


int main() {
    auto v1 = countArgs1(1, 2, 3, 4, 5);  // Version 1
    auto v2 = countArgs2(123, 44, 7, 54); // Version 2

    std::cout << "Version 1: " << v1 << std::endl;
    std::cout << "Version 2: " << v2 << std::endl;
    
    return 0;
}