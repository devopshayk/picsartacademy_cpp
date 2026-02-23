#include <iostream>


template<typename... Arg>
auto minValue(Arg... args) {
    using Common = std::common_type_t<Arg...>;
    return std::min({ static_cast<Common>(args)... });
}

template<typename F, typename... Arg>
auto minValue2(F first, Arg... args) {
    auto res = first;
    ((res = (args < res ? args : res)), ...);
    
    return res;
}

int main() {
    auto v1 = minValue(5, 6.6, -3, -1, 123);  // Version 1
    auto v2 = minValue2(5, 6.6, -3, -1, 123); // Version 2

    std::cout << "Version 1: " << v1 << std::endl;
    std::cout << "Version 2: " << v2 << std::endl;

    return 0;
}