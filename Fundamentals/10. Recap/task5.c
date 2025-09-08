#include <stdio.h>

	int main() {
		const int  size = 50;
		char arr[size];

		int i = 0;

		printf("Write text: ");
		fgets(arr, sizeof(arr), stdin);
		
		while(arr[i] != '\0') {
			if(arr[i] >= 'a' && arr[i] <= 'z') {
				arr[i] -= 32;
			}
			
			i++;
		}

		fprintf(stdout, "Text: %s", arr);

		return 0;
	}
