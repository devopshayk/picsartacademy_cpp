#include <stdio.h>
#include <stdlib.h>

	int main() {
    		int size = 0;

    		printf("Write size for float array: ");
    		scanf("%d", &size);

    		float *arr = (float *)calloc(size, sizeof(float));

    		printf("Write %d elements for array: ", size);
    		for(int i = 0; i < size; i++) {
        		scanf("%f", &arr[i]);
    		}

    		puts("");

    		printf("Array's elements: ");
    		for(int i = 0; i < size; i++) printf(" %.2f", arr[i]);

    		puts("");

    		free(arr);

    		return 0;
	}

