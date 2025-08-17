#include <stdio.h>
	
	void count_repeat(int * arr, int size);
		
	int main() {
		const int SIZE = 10;
		int arr[SIZE];

		printf("Write %d nums for array: ", SIZE);
		for(int i = 0; i < SIZE; i++) scanf("%d", &arr[i]);
		
		puts("");

		count_repeat(arr, SIZE);

		return 0;	
	}

	void count_repeat(int * arr, int size) {
		int count = 0;

		for(int i = 0; i < size; i++) {
			count = 1;
	
			for(int j = i + 1; j < size; j++) {
				if(arr[i] == arr[j]) count++;
			}
				
			if(count > 1) printf("%d num repeated %d times\n", arr[i], count);
			else printf("%d num don't repeat \n", arr[i]);
			
			i += count - 1;	
		}
	}
