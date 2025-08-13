#include <stdio.h>
#include <string.h>

#define SIZE 50

	void to_uppercase(char str[]);
	
	int main() {
		char arr[SIZE];

		fputs("Write text for converting to uppercase: ", stdout);
		fgets(arr, SIZE, stdin);
		arr[strcspn(arr, "\n")] = '\0';

		puts("");

		to_uppercase(arr);

		puts("");

		return 0;
	}

	void to_uppercase(char str[]) {
		char * original = str;

		while(*str) {
			if(*str >= 'a' && *str <= 'z') *str -= 'a' - 'A';
			str++;
		}

		printf("Result is: %s", original);
	}
