#include <stdio.h>

#define SIZE 5

	void reverseArray(int arr[], int size);

	int main() {
		int arr[SIZE];
		
		printf("Write %d elements for reverse array: ", SIZE);
		for(int i = 0; i < SIZE; i++) scanf("%d", &arr[i]);

		printf("Reversed array: ");
		reverseArray(arr, SIZE);

		return 0;		
	}

	void reverseArray(int arr[], int size) {
		int * start = arr;
		int * end = arr + size - 1;

		while(start < end) {
			int tmp = *start;
			*start = *end;
			*end = tmp;
			
			start++;
			end--;	
		}

		for(int i = 0; i < size; i++) printf("%d ", arr[i]);
		printf("\n");
	}
