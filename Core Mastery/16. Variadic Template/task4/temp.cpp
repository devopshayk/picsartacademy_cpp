#include <iostream>

template<typename... Arg>
bool allTrue1(Arg... args) {
    return (... && args);
}

template<typename... Arg>
bool allTrue2(Arg... args) {
    return (args && ...);
}


int main() {
    auto v1 = allTrue1(true, true, true, true);   // Version 1
    auto v2 = allTrue2(false, true, true, false); // Version 2

    std::cout << "Version 1: " << (v1 ? "True" : "False") << std::endl;
    std::cout << "Version 2: " << (v2 ? "True" : "False") << std::endl;
    
    return 0;
}