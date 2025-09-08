#include <stdio.h>

	int main() {
		int size = 0, target = 0;

		printf("\t Detecting number in array\n\n");

		printf("Write size for array: ");	
		scanf("%d", &size);

		int arr[size];
	
		printf("Write %d elements for array: ", size);
		for(int i = 0; i < size; i++) {
			scanf("%d", &arr[i]);
		}

		printf("Write number for detection: ");
		scanf("%d", &target);

		for(int i = 0; i < size; i++) {
			if(target == arr[i]) {
				printf("\nYES\n");
				return 0;
			}
		}

		printf("\nNO\n");

		return 0;
	}
