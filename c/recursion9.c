#include <stdio.h>

	char firstUppercase(const char *str);

	int main() {
		char text[] = "Hello World";

		printf("%c", firstUppercase(text));

		return 0;
	}

	char firstUppercase(const char *str) {
		if(*str == '\0') return *str;

		if (*str >= 'A' && *str <= 'Z') return *str;
    
    		return firstUppercase(str + 1);
	}
