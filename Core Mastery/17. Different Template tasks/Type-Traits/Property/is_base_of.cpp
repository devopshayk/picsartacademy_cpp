#include <iostream>

template<typename Base, typename Derived>
struct is_base_of {
    private:
        static std::true_type test(Base*);

        static std::false_type test(...);

    public:
        static const bool value =
            decltype(test((Derived*)nullptr))::value;
};


struct A {};
struct B : A {};
struct C {};

int main() {
    std::cout << is_base_of<A, B>::value << std::endl;
    std::cout << is_base_of<A, C>::value << std::endl;
    std::cout << is_base_of<A, A>::value << std::endl;

    return 0;
}