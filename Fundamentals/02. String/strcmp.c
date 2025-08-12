#include <stdio.h>
#include <string.h>

	int strCmp(const char* lhs, const char* rhs);

	int main() {
		char lhs[50];
		char rhs[50];

		fputs("Write text(lhs) for compare: ", stdout);
		
		fgets(lhs, 100, stdin);
		lhs[strcspn(lhs, "\n")] = '\0';

		fputs("Write text(rhs) for compare: ", stdout);
		
		fgets(rhs, 50, stdin);
		rhs[strcspn(rhs, "\n")] = '\0';

		int result = strCmp(lhs, rhs);
		
		puts(""); 

		fprintf(stdout, "Result is %d\n", result);

		return 0;
	}

	int strCmp(const char* lhs, const char* rhs) {
		int i = 0;
		
		while(lhs[i] != '\0' && rhs[i] != '\0') {
			if(lhs[i] != rhs[i]) return -1;

			i++;
		}

		return (lhs[i] == '\0' && rhs[i] == '\0') ? 0 : -1;
	}
