#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <set>


template<typename T>
auto sumContainer(const T& container) {
    int sum{};

    for(const auto& cnt : container) {
        sum += cnt;
    }

    return sum;
}


int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Sum of vector<int>: " << sumContainer(vec) << std::endl;

    std::list<double> lst = {1.5, 2.5, 3.5, 4.5};
    std::cout << "Sum of list<double>: " << sumContainer(lst) << std::endl;

    std::deque<float> dq = {10.0f, 20.0f, 30.0f};
    std::cout << "Sum of deque<float>: " << sumContainer(dq) << std::endl;

    std::array<int, 4> arr = {100, 200, 300, 400};
    std::cout << "Sum of array<int>: " << sumContainer(arr) << std::endl;

    std::set<int> s = {5, 10, 15, 20};
    std::cout << "Sum of set<int>: " << sumContainer(s) << std::endl;

    return 0;
}