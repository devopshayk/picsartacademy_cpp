#include <iostream>
#include "shared.hpp"

struct Test {
    int x;
    Test(int v) : x(v) { std::cout << "Ctor: " << x << "\n"; }
    ~Test() { std::cout << "Dtor: " << x << "\n"; }
};

int main() {
    std::cout << "---- Basic construction ----\n";
    shared_ptr<Test> p1(new Test(10));
    std::cout << "count = " << p1.use_count() << "\n";

    {
        std::cout << "---- Copy constructor ----\n";
        shared_ptr<Test> p2 = p1;
        std::cout << "p1 count = " << p1.use_count() << "\n";
        std::cout << "p2 count = " << p2.use_count() << "\n";

        std::cout << "---- Another copy ----\n";
        shared_ptr<Test> p3(p2);
        std::cout << "p1 count = " << p1.use_count() << "\n";
        std::cout << "p3 count = " << p3.use_count() << "\n";
    }

    std::cout << "---- After scope end ----\n";
    std::cout << "p1 count = " << p1.use_count() << "\n";

    std::cout << "---- Move constructor ----\n";
    shared_ptr<Test> p4(std::move(p1));
    std::cout << "p1 count = " << p1.use_count() << "\n";
    std::cout << "p4 count = " << p4.use_count() << "\n";

    std::cout << "---- reset ----\n";
    p4.reset(new Test(50));
    std::cout << "p4 count = " << p4.use_count() << "\n";

    std::cout << "---- swap ----\n";
    shared_ptr<Test> a(new Test(100));
    shared_ptr<Test> b(new Test(200));

    a.swap(b);
    std::cout << "a = " << a->x << ", b = " << b->x << "\n";

    std::cout << "---- Move assignment ----\n";
    shared_ptr<Test> c(new Test(300));
    shared_ptr<Test> d;
    d = std::move(c);
    std::cout << "c count = " << c.use_count() << "\n";
    std::cout << "d count = " << d.use_count() << "\n";

    shared_ptr<Test> dw(nullptr);
    shared_ptr<Test> dww = dw;

    std::cout << "---- END ----\n";
}
