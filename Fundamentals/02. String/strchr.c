#include <stdio.h>
#include <string.h>

	char * strChr(char * str, int target);

	int main() {
    		char text[50];
    		char sym;

    		fputs("Write text: ", stdout);
    		
		fgets(text, 50, stdin);
    		text[strcspn(text, "\n")] = '\0';

    		fputs("Write sym for search: ", stdout);
    		fscanf(stdin, " %c", &sym);

    		char * result = strChr(text, sym);
		
		puts("");

    		fprintf(stdout, "%s\n", result ? result : "Symbol not found");

    		return 0;
	}

	char * strChr(char * str, int target) {
    		while (*str) {
        		if (*str == target) return str;
        		str++;
    		}
   		
		 return NULL;
	}

