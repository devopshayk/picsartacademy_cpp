#include <iostream>
#include <string>

template<typename... Arg>
void printAll1(Arg... args) {
    ((std::cout << args << "\n"), ...);
}

template<typename... Arg>
void printAll2(Arg... args) {
    (std::cout << ... << (std::string(args) + "\n"));
}


int main() {
    printAll1("hayk", 23523, 'p');       // Version 1
    printAll2("hayk", "poghosyan", "m"); // Version 2 (only for strings)

    return 0;
}