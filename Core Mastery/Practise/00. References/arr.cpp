#include <iostream>

    int main() {
        int arr[3] = {1, 2, 3};

        int& r = arr[0];

        std::cout << "Write number for array's first element: ";
        std::cin >> r;

        std::cout << std::endl;

        std::cout << "New array: ";
        for(int i = 0; i < 3; i++) std::cout << arr[i];
        std::cout << std::endl;

        return 0;
    }