#include <stdio.h> 

	void remove_duplicates(int arr[], int * size);

	int main() {
		int size;
		
		printf("Write size for array: ");
		scanf("%d", &size);

		int arr[size];

		printf("Write %d elements for array: ", size);
		for(int i = 0; i < size; i++) scanf("%d", &arr[i]);

		puts("");
		
		printf("Removed array: ");
		remove_duplicates(arr, &size);
		puts("");

		return 0;
	}

	void remove_duplicates(int arr[], int * size) {
		for(int i = 0; i < *size; i++) {
			for(int j = i + 1; j < *size; j++) {
				if(arr[i] == arr[j]) {
					for(int k = j; k < *size - 1; k++) {
						arr[k] = arr[k + 1];
					}
					
					j--;
					(*size)--;
				}
			}
		}
		
		for(int i = 0; i < *size; i++) printf("%d", arr[i]);
	}
