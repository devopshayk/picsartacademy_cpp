#include <stdio.h>

	int main() {
		const int size = 50;
		char arr[size];

		printf("Write text: ");
		fgets(arr, sizeof(arr), stdin);
		
		printf("Result is: ");
		for(int i = 0; arr[i] != '\0'; i++) {
			if(arr[i] >= '0' && arr[i] <= '9') printf("%c", arr[i]);
		}

		printf("\n");

		return 0;
	}
