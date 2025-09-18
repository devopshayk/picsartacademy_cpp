#include <iostream>
#include <string>

    int main() {
        std::string name;;
        int age;

        std::cout << "Write age: ";
        std::cin >> age;

        std::cout << "Write name: ";
        std::cin >> name;

        std::cout << "Name is " << name << ", Age " << age << std::endl;

        return 0;
    }