#include <stdio.h>
#define SIZE 5

	void multiply_elems(int * arr1, int * arr2, int size);
	
	int main() {
		int arr1[SIZE];
		int arr2[SIZE];

		printf("Write %d elements for arr1: ", SIZE);
		for(int i = 0; i < SIZE; i++) scanf("%d", &arr1[i]);

		printf("Write %d elements for arr2: ", SIZE);
		for(int i = 0; i < SIZE; i++) scanf("%d", &arr2[i]);

		puts("");

		printf("Multiply elements with the same index: ");
		multiply_elems(arr1, arr2, SIZE);
		
		puts("");

		return 0; 
	}

	void multiply_elems(int * arr1, int * arr2, int size) {
		for(int i = 0; i < size; i++) printf("%d ", arr1[i] * arr2[i]);
	}
