#include <iostream>

template<typename... Arg>
bool anyTrue1(Arg... args) {
    return (... || args);
}

template<typename... Arg>
bool anyTrue2(Arg... args) {
    return (args || ...);
}


int main() {    
    auto v1 = anyTrue1(false, false, true, false);  // Version 1 
    auto v2 = anyTrue2(false, false, false, false); // Version 2

    std::cout << "Version 1: " << (v1 ? "True" : "False") << std::endl;
    std::cout << "Version 2: " << (v2 ? "True" : "False") << std::endl;
   
    return 0;
}