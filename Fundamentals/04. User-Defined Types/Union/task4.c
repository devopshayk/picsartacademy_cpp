#include <stdio.h>

	typedef union {
    		int length;
    		float weight;
	} Measurement;

	int main() {
    		Measurement m;
    		int choice;

    		printf("\tChoose what to enter:\n\n");
    		printf("1. Length (int)\n");
    		printf("2. Weight (float)\n");
    
		printf("Choice: ");
    		scanf("%d", &choice);

    		if(choice == 1) {
        		printf("Enter length: ");
        		scanf("%d", &m.length);
        		printf("\nStored length = %d\n", m.length);
    		} else if(choice == 2) {
        		printf("Enter weight: ");
        		scanf("%f", &m.weight);
        		printf("\nStored weight = %.2f\n", m.weight);
    		} else {
        		printf("Invalid choice!\n");
    		}

    		return 0;
	}

