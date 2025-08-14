#include <stdio.h>

	void merge_sorted_arrays(int arr1[], int size1, int arr2[], int size2, int result[]);
	
	int main() {
		int result[50];
		
		int size1;
		printf("Write size for array 1: ");
		scanf("%d", &size1);

		int arr1[size1];

		int size2;
		printf("Write size for array 2: ");
		scanf("%d", &size2);

		int arr2[size2];

		puts("");

		printf("Write %d elements for array 1: ", size1);
		for(int i = 0; i < size1; i++) scanf("%d", &arr1[i]);

		printf("Write %d elements for array 2: ", size2);
		for(int i = 0; i < size2; i++) scanf("%d", &arr2[i]);

		merge_sorted_arrays(arr1, size1, arr2, size2, result);

		puts("");

		fputs("Result is: ", stdout);
		for(int i = 0; i < size1 + size2; i++) printf("%d ", result[i]);
		puts("");

		return 0;
	}

	void merge_sorted_arrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
		int k = 0;
	
		for(int i = 0; i < size1; i++) result[k++] = arr1[i];
		for(int j = 0; j < size2; j++) result[k++] = arr2[j];

		for(int i = 0; i < k - 1; i++) {
			for(int j = 0; j < k - 1 - i; j++) {
				if(result[j] > result[j + 1]) {
					int tmp = result[j];
					result[j] = result[j + 1];
					result[j + 1] = tmp;
				}
			}		
		}
	}
