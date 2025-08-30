#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	int main() {
    		char buffer[1000];
    		char *str;

    		printf("Write text: ");
    		fgets(buffer, sizeof(buffer), stdin);
    		buffer[strcspn(buffer, "\n")] = '\0';

    		str = malloc(strlen(buffer) + 1);

    		strcpy(str, buffer);

    		printf("Text: \"%s\"\n", str);
    		printf("Length: %zu\n", strlen(str));

    		free(str);
    		
			return 0;
	}

