#include <stdio.h>
#include <string.h>

	void serach_sym(char * str, char ch);

	int main() {
		char str[50];
		char ch;

		fputs("Write text for string: ", stdout);

		fgets(str, sizeof(str), stdin);
		str[strcspn(str, "\n")] = '\0';

		printf("Write text for ch(search symbol in src): ");
		scanf(" %c", &ch);

		puts("");

		printf("Result is -> ");	
		serach_sym(str, ch);
		
		return 0;
	}

	void serach_sym(char * str, char ch) {
		char * start = str;	
	
		while(*str) {
			if(*str == ch) *str = ' ';
			str++;
		}

		printf("%s\n", start);
	}
