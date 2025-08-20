#include <stdio.h>
#include <string.h>

	char* strstr( const char* str, const char* substr );

	int main() {
		char str[50];
		char substr[25];

		fgets(str, sizeof(str), stdin);
		str[strcsnp(str, "\n")] = '\0';

		fgets(substr, sizeof(substr), stdin);
		substr[strcsnp(substr, "\n")] = '\0';

		char * result = strstr(char* str, substr);
	
		printf("%s", result);

		return 0;
	}

	char* strstr( const char* str, const char* substr ) {
		int count = 0;
		///
	}
