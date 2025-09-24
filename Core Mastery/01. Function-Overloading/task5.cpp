#include <iostream>
#include <string>

    void print(int x);
    void print(const std::string& s);
    void print(const int arr[], int size);

    int main() {
        int x = 42;
        std::string str = "Hello";
        int arr[] = {1, 2, 3, 4, 5};
        int arrSize = sizeof(arr) / sizeof(arr[0]);

        print(x);
        print(str);
        print(arr, arrSize);

        return 0;
    }


    void print(int x) {
        std::cout << "Integer: " << x << std::endl;
    }

    void print(const std::string& s) {
        std::cout << "String: " << s << std::endl;
    }

    void print(const int arr[], int size) {
        std::cout << "Array: ";
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }