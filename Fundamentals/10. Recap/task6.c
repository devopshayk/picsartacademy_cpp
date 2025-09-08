#include <stdio.h>

	int main() {
		int size = 0, count = 0;

		printf("Write size for arrays: ");
		scanf("%d", &size);

		int arr1[size], arr2[size];

		printf("\nWrite %d elements for array 1: ", size);
		for(int i = 0; i < size; i++) scanf("%d", &arr1[i]);

		printf("Write %d elements for array 2: ", size);
		for(int i = 0; i < size; i++) scanf("%d", &arr2[i]);

		for(int i = 0; i < size; i++) {
			if(arr1[i] == arr2[i]) count++;
		}

		if(count == size) printf("\nYes arrays are same\n");
		else printf("\nNo, arrays are not same\n");
	}
