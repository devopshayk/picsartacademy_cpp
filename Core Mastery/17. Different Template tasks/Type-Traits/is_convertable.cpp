#include <iostream>

template<typename From, typename To>
struct is_convertible {
    private:
        static void test(To);

        template<typename F, typename = decltype(test(std::declval<F>()))>
        static std::true_type helper(int);

        template<typename>
        static std::false_type helper(...);

    public:
        static const bool value = decltype(helper<From>(0))::value;
};


int main() {
    std::cout << is_convertible<int, double>::value << std::endl;
    std::cout << is_convertible<int*, void*>::value << std::endl;
    std::cout << is_convertible<void*, int*>::value << std::endl;

    return 0;
}