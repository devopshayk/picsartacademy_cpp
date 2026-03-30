#include <iostream>

template<typename T>
struct has_operator_plus {
    private:
        template<typename U>
        static auto test(int) -> decltype(std::declval<U>() + std::declval<U>(), std::true_type());

        template<typename>
        static std::false_type test(...);
    public:
        static const bool value = decltype(test<T>(0))::value;
};


struct A {};

struct B {
    B operator+(const B&) {
        return B{};
    }
};

int main() {
    std::cout << has_operator_plus<int>::value << std::endl;
    std::cout << has_operator_plus<A>::value << std::endl;
    std::cout << has_operator_plus<B>::value << std::endl;

    return 0;
}