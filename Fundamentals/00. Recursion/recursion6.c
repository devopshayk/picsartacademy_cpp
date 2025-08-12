#include <stdio.h>

#define SIZE 5

        void print_arr(int * arr, int size);

        int main() {
                int arr[SIZE] = {1, 2, 3, 4, 5};

                print_arr(arr, SIZE);

                return 0;
        }

        void print_arr(int * arr, int size) {
                if(size == 0) return;
                printf("%d", arr[size - 1]);
                print_arr(arr, size - 1); // reversed
        }
