#include <stdio.h>
#include <string.h> // For strcspn() function

	char* strRchr(char* str, int ch);
		
	int main() {
		char text[50];
		char sym;

		fputs("Write text: ", stdout);

		fgets(text, 50, stdin);
		text[strcspn(text, "\n")] = '\0';

		fputs("Write sym for search: ", stdout);
		fscanf(stdin, " %c", &sym);
		
		char * result = strRchr(text, sym);

		puts("");

		fprintf(stdout, "%s", result ? result : "Symbol not found\n");

		return 0;
	}


	char* strRchr(char* str, int ch) {
		char * last = NULL;
		
		while(*str != '\0') {
			if(*str == ch) last = str;
			str++;
		}
		
		return last;
	}	
