#include <iostream>
#include <algorithm>


template<typename T>
void sortArray(T* arr, int size) {
    for(int i = 0; i < size - 1; ++i) {
        for(int j = 0; j < size - i - 1; ++j) {
            if(arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


int main() {
    int nums[] = {64, 34, 25, 12, 22, 11, 90};
    char letters[] = {'z', 'a', 'm', 'b', 'k'};
    double decimals[] = {3.14, 1.41, 2.71, 0.5, 9.99};
    
    sortArray(nums, 7);
    sortArray(letters, 5);
    sortArray(decimals, 5);
    
    for(int num : nums) std::cout << num << " ";
    std::cout << std::endl;
    
    for(char ch : letters) std::cout << ch << " ";
    std::cout << std::endl;
    
    for(double d : decimals) std::cout << d << " ";
    std::cout << std::endl;
    
    return 0;
}