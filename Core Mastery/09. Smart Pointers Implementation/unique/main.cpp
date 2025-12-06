#include <iostream>
#include "uniqe.hpp"

struct Test {
    int x;
    Test(int v) : x(v) { std::cout << "Ctor: " << x << "\n"; }
    ~Test() { std::cout << "Dtor: " << x << "\n"; }
};

int main() {
    std::cout << "---- Basic construction ----\n";
    uniqe_ptr<Test> p1(new Test(10));
    std::cout << (*p1).x << "\n";

    std::cout << "---- Move constructor ----\n";
    uniqe_ptr<Test> p2(std::move(p1)); 
    std::cout << p2->x << "\n";
    std::cout << (p1.get() == nullptr ? "p1 empty\n" : "p1 not empty\n");

    std::cout << "---- Move assignment ----\n";
    uniqe_ptr<Test> p3(new Test(20));
    p2 = std::move(p3);
    std::cout << p2->x << "\n";
    std::cout << (p3.get() == nullptr ? "p3 empty\n" : "p3 not empty\n");

    std::cout << "---- reset ----\n";
    p2.reset(new Test(30));      
    std::cout << p2->x << "\n";

    std::cout << "---- release ----\n";
    Test* raw = p2.release();
    std::cout << (p2.get() == nullptr ? "p2 empty after release\n" : "p2 not empty\n");
    delete raw;

    std::cout << "---- swap ----\n";
    uniqe_ptr<Test> a(new Test(100));
    uniqe_ptr<Test> b(new Test(200));

    a.swap(b);
    std::cout << "a = " << a->x << ", b = " << b->x << "\n";

    std::cout << "---- END ----\n";
}
