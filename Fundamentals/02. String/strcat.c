#include <stdio.h>
#include <string.h> // For strcspn() function

	char * strCat(char* dest, const char* src);

	int main() {
		char dest[100];
		char src[50];

		fputs("Write text for destination: ", stdout);
		
		fgets(dest, 100, stdin);
		dest[strcspn(dest, "\n")] = '\0';

		fputs("Write text for source: ", stdout);
		
		fgets(src, 50, stdin);
		src[strcspn(src, "\n")] = '\0';

		char * result = strCat(dest, src);
		
		puts(""); // For '\n'

		fprintf(stdout, "Concat result = %s\n", result);

		return 0;
	}

	char * strCat(char* dest, const char* src) {
		int index = 0;

		while(dest[index] != '\0') index++;
		
		dest[index] = ' ';
		index++; 

		while(*src) {	
			dest[index] = *src;	
			index++;
			src++;
		}
		
		dest[index] = '\0';

		return dest;	
	}
