#include <stdio.h>

#define SIZE 50

	void to_uppercase(char str[]);
	
	int main() {
		char str[SIZE];

		fputs("Write text for converting to uppercase: ", stdout);
		fgets(str, SIZE, stdin);

		puts("");

		to_uppercase(str);

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
