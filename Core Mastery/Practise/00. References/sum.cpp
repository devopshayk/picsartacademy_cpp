#include <iostream>

    void sum(int &a, int &b, int &res);

    int main() {
        int res{0};
        int a, b;
        
        std::cout << "Write two numbers for sum: ";
        std::cin >> a >> b;

        std::cout << "Result is: ";
        sum(a, b, res);
        std::cout << std::endl;

        return 0;
    }

    void sum(int &a, int &b, int &res) {
        res = a + b;
        std::cout << res;
    }