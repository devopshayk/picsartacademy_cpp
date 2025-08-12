#include <stdio.h>

	int strLen(const char * str);

	int main() {
		char str[50];

		fputs("Write text for detected size: ", stdout);
		fgets(str, sizeof(str), stdin);

		int result = strLen(str);
		
		printf("Size of text = %d\n", result);

		return 0;
	}

	int strLen(const char * str) {
		int count = 0;

		while(str[count] != '\0' && str[count] != '\n') count++; // Function fgets() adds '\n' at the end if there is space.

		return count;
	}
