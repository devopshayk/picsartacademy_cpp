#include <stdio.h>
#include <stdlib.h>

	int main() {
		int size = 0;

		printf("Write size for array: ");
		scanf("%d", &size);

		int * arr = (int *)malloc(size * sizeof(int)); 

		printf("Write %d elements for array: ", size);
		for(int i = 0; i < size; i++) {
			 scanf("%d", &arr[i]);
		}

		puts("");

		printf("Array's elements: ");
		for(int i = 0; i < size; i++) printf(" %d", arr[i]);
		
		puts("");

		free(arr);

		return 0;
	}
