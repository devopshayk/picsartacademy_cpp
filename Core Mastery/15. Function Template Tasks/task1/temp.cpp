#include <iostream>
#include <cctype>


template<typename T>
void printValue(T arg) {
    std::cout << "Unknown type." << std::endl;
}

template<>
void printValue<int>(int arg) {
    std::cout << "Integer: " << arg << std::endl;
}

template<>
void printValue<double>(double arg) {
    std::cout << "Double: " << arg << std::endl;
}

template<>
void printValue<const char *>(const char * arg) {
    while(*arg) {
        std::cout << static_cast<unsigned char>(std::toupper(*arg));
        ++arg;
    }

    std::cout << "\n";
}


int main() {
    int intArg = 5;
    double doubleArg = 12.3;
    float floatArg = 20.0;
    std::string stringArg = "Hayk";
    
    
    printValue(intArg);
    printValue(doubleArg);
    printValue(floatArg);
    printValue("hello");
    printValue(stringArg);

    return 0;
}