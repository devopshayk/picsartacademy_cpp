#include <stdio.h>

	int findMax(int arr[], int n) {
    		if (n == 1) return arr[0];

    		int max_rest = findMax(arr + 1, n - 1);
   			return (arr[0] > max_rest) ? arr[0] : max_rest;
	}


	int main() {
    		int arr[] = {5, 2, 9, 1, 7};
    		
			int size = sizeof(arr) / sizeof(arr[0]);

    		int max = findMax(arr, size);
    		printf("%d\n", max);

    		return 0;
	}

