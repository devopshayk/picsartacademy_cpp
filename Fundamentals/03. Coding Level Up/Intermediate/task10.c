#include <stdio.h>
#include <string.h>

	char * strCat(char * dest, const char * src);

	int main() {
		char dest[100];
		char src[50];

		fputs("Write text for destination: ", stdout);

		fgets(dest, sizeof(dest), stdin);
		dest[strcspn(dest, "\n")] = '\0';

		fputs("Write text for source: ", stdout);

		fgets(src, sizeof(src), stdin);
		src[strcspn(dest, "\n")] = '\0';

		char * result = strCat(dest, src);

		puts("");

		fprintf(stdout, "Result is -> %s\n", result);

		return 0;	
	}

	char * strCat(char * dest, const char * src) {
		int index = 0;		
	
		while(dest[index] != '\0') index++;

		dest[index] = ' ';
		index++;

		while(*src) {
			dest[index] = *src;
			src++;
			index++;				
		}

		dest[index] = '\0';

		return dest;
	}
