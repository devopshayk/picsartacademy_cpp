#include <iostream>

class Base {
    public: 
    Base() {
        std::cout << 5;
    }
};

class Derived : public Base {
    public:
        Derived() {
            std::cout << 5;
        }
};

int main () {
    Base * ptr = new Derived;
}