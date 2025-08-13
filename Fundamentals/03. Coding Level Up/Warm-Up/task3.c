#include <stdio.h>

#define SIZE 50

	void print_digits(char arr[], int size);

	int main() {
		char arr[SIZE];
		
		fputs("Write symbols for filtering digits: ", stdout);
		fgets(arr, SIZE, stdin);

		puts("");

		fputs("Filtered result: ", stdout);
		print_digits(arr, SIZE);

		puts("");

		return 0;
	}

	void print_digits(char arr[], int size) {
		for(int i = 0; i < SIZE; i++) {
			if(arr[i] >= '0' && arr[i] <= '9') printf("%c ", arr[i]); 
		}
	}
