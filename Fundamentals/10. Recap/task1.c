#include <stdio.h>

	int main() {
		int size = 0, result = 0;

		printf("Write size for arrays: ");
		scanf("%d", &size);
		
		int arr1[size], arr2[size];

		printf("\n");

		printf("Write %d elements for array 1: ", size);
		for(int i = 0; i < size; i++) {
			scanf("%d", &arr1[i]);
		}

		printf("Write %d elements for array 2: ", size);
		for(int i = 0; i < size; i++) {
			scanf("%d", &arr2[i]);
		}

		printf("\n");

		printf("Result is: ");
		for(int i = 0; i < size; i++) {
			int result = arr1[i] * arr2[i];
			printf("%d ", result);
		}

		printf("\n");

		return 0;
	}
