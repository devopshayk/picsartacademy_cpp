#include <stdio.h>

	typedef union {
    		int intValue;
    		float floatValue;
	} Number;

	int main() {
    		Number num;

    		printf("Enter an integer: ");
    		scanf("%d", &num.intValue);
    
		printf("As int: %d\n", num.intValue);
    		printf("As float: %f\n", num.floatValue);

    		printf("\nEnter a float: ");
    		scanf("%f", &num.floatValue);
    
		printf("As float: %f\n", num.floatValue);
    		printf("As int: %d\n", num.intValue);

    		return 0;
	}

