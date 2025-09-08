#include <stdio.h>

	int main() {
		int size = 0;
		int result = 0, sum = 0;

		printf("Write size for array: ");
		scanf("%d", &size);
		
		int arr[size];

		printf("Write %d elements for array: ", size);
		for(int i = 0; i < size; i++) {
			scanf("%d", &arr[i]);
		}

		for(int i = 0; i < size; i++) {
			sum += arr[i];
		}
		
		result = sum / size;

		printf("\nResult is %d\n", result);

		return 0;
	}
