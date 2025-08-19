#include <stdio.h>

	typedef struct {
    		float weight;
    		float height;
	} Person;

	int main() {
    		Person p;
    		float bmi;

    		printf("\tEnter weight (kg) and height (m)\n\n");

    		printf("Weight: ");
    		scanf("%f", &p.weight);
    
			printf("Height: ");
    		scanf("%f", &p.height);

    		bmi = p.weight / (p.height * p.height);

    		printf("\nBMI = %.2f\n", bmi);

    		if (bmi < 18.5)
        		printf("Category: Underweight\n");
    		else if (bmi < 25.0)
        		printf("Category: Normal\n");
    		else
        		printf("Category: Overweight\n");

    		return 0;
	}

