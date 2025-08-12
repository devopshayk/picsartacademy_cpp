#include <stdio.h>
#include <string.h> // For strcspn() function

	char * strCpy(const char * str1, char * str2);

	int main() {
		char str1[50];
		char str2[50];
		
		fputs("Write text for Str1: ", stdout);
		
		fgets(str1, 50, stdin);
		str1[strcspn(str1, "\n")] = '\0'; // For deleted '\n' symbol		

		char * result = strCpy(str1, str2);

		fprintf(stdout, "Str2 value = %s\n", result);

		return 0;
	}

	char * strCpy(const char * str1, char * str2) {
		int index = 0;

		while(str1[index] != '\0') {
			str2[index] = str1[index];
			index++;
		}
		
		str2[index] = '\0';

		return str2;
	}
