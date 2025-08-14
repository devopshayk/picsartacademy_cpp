#include <stdio.h>

	int arrays_are_equal(const int arr1[], size_t size1, const int arr2[], size_t size2);

	int main() {
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
		
		puts("");

		int result = arrays_are_equal(arr1, size1, arr2, size2);

		printf("%s", arrays_are_equal(arr1, size1, arr2, size2) ? "Yes, arrays is equal\n" : "No, arrays is not equal\n");

		return 0;
	}

	int arrays_are_equal(const int arr1[], size_t size1, const int arr2[], size_t size2) {
		int check = 0;
	
		for(int i = 0; i < size1; i++) if(arr1[i] == arr2[i]) check++;
		
		if(check == size1 && check == size2) return 1;
		else return 0;
	}
