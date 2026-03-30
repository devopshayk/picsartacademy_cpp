#include <iostream>

template<typename T>
struct is_default_constructible {
    private:
        template<typename U, typename = decltype(U())>
        static std::true_type test(int);

        template<typename>
        static std::false_type test(...);

    public:
        static const bool value = decltype(test<T>(0))::value;
};


struct A {
    A() {}
};

struct B {
    B(int) {}
};

int main() {
    std::cout << is_default_constructible<A>::value << std::endl;
    std::cout << is_default_constructible<B>::value << std::endl;

    return 0;
}