#include <iostream>

class Test {
    private:
        int x;
    public:
        Test() {
            x = 42;
            std::cout << "ctor is called: ";
        }

        ~Test() {
            std::cout << "Dtor is called";
        }

        int getX() const { return x; }
};

int main() {
    Test  t;
    std::cout << t.getX();
}