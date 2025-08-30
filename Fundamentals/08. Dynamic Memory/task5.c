#include <stdio.h>
#include <stdlib.h>

	int main() {
		int size = 0;

		printf("Write size for int array: ");
		scanf("%d", &size);

		int *arr = (int *)malloc(size * sizeof(int));

		printf("Write %d elements for array: ", size);
		for(int i = 0; i < size; i++) {
			scanf("%d", &arr[i]);
		}

		int new_elements = 0;
		printf("Write number of new elements to add: ");
		scanf("%d", &new_elements);

		arr = (int *)realloc(arr, (size + new_elements) * sizeof(int));

		printf("Write %d new elements: ", new_elements);
		for(int i = size; i < size + new_elements; i++) {
			scanf("%d", &arr[i]);
		}

		size += new_elements;

		puts("");
		printf("Array's elements:");
		for(int i = 0; i < size; i++) printf(" %d", arr[i]);

		puts("");
		free(arr);

		return 0;
	}
