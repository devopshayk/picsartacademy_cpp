// & && const & lvalue rvalue tmp a.o
// Class Relioshenship
// virtual, inch ktipiner
// vtable, value category
#include <iostream>
class Base { public: int x; };
class Derived : public Base { char c; };
int main() {
    Derived d;

    std::cout << sizeof(Derived);
    std::cout << d.x;
}
