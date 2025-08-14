#include <stdio.h>
	
	void shift_to_left(int arr[], int size);

        int main() {
                int size;
		
		printf("Write size for array: ");
		scanf("%d", &size);

		int arr[size];

		printf("Write %d elements for array: ", size);
		for(int i = 0; i < size; i++) scanf("%d", &arr[i]);

		shift_to_left(arr, size);		
		
		puts("");		

		return 0;
	}
	
	void shift_to_left(int arr[], int size) {
                int count = 0, k = 0;

		printf("Write count for shift left: ");
		scanf("%d", &k);

                while(count != k) {
                        int tmp = arr[0];

                        for(int i = 0; i < size; i++) arr[i] = arr[i+1];

                        arr[size - 1] = tmp;
                        ++count;
                }

		printf("\n");

		printf("Result is: ");
                for(int i = 0; i < size; i++) printf("%d ", arr[i]);
        }
