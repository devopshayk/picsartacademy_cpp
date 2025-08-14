#include <stdio.h> ///////////////

	void remove_duplicates(int arr[], int size);

	int main() {
		int size;
		
		printf("Write size for array: ");
		scanf("%d", &size);

		int arr[size];

		printf("Write %d elements for array: ", size);
		for(int i = 0; i < size; i++) scanf("%d", &arr[i]);

		remove_duplicates(arr, size);
		
		puts("");
		
		return 0;
	}

	void remove_duplicates(int arr[], int size) {
		for(int i = 0; i < size - 1; i++) {
			for(int j = 0; j < size - i - 1; j++) {
				if(arr[j] > arr[j + 1]) {
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}

		for(int i = 0; i < size; i++) printf("%d ", arr[i]);
	}
