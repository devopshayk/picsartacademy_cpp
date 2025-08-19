#include <stdio.h>

	typedef union {
   			float floatValue;
    		int intValue;
	} Value;

	int main() {
    		Value v;

    		printf("Enter a float: ");
    		scanf("%f", &v.floatValue);

    		printf("\nfloatValue = %.2f\n", v.floatValue);
    		printf("intValue (bit representation) = %d\n", v.intValue);

    		return 0;
	}

