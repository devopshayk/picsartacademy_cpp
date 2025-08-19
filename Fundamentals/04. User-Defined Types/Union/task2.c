#include <stdio.h>

	typedef union {
    		int intValue;
    		char charValue;
	} Data;

	int main() {
    		Data d;

    		printf("Enter an integer: ");
    		scanf("%d", &d.intValue);

    		printf("\nintValue = %d\n", d.intValue);
    		printf("charValue (first byte of int) = %c\n", d.charValue);

    		return 0;
	}

