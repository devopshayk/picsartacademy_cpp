#include <stdio.h>

	typedef struct {
    		int numerator;
    		int denominator;
	} Rational;

	int main() {
    		Rational r1, r2, sum, product;

    		printf("\tEnter the first rational number\n\n");

    		printf("Numerator: ");
    		scanf("%d", &r1.numerator);
    		
		printf("Denominator: ");
    		scanf("%d", &r1.denominator);

    		printf("\n\tEnter the second rational number\n\n");

    		printf("Numerator: ");
    		scanf("%d", &r2.numerator);
    
		printf("Denominator: ");
    		scanf("%d", &r2.denominator);

    		sum.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    		sum.denominator = r1.denominator * r2.denominator;

    		product.numerator = r1.numerator * r2.numerator;
    		product.denominator = r1.denominator * r2.denominator;

    		printf("\nSum = %d/%d\n", sum.numerator, sum.denominator);
    		printf("Product = %d/%d\n", product.numerator, product.denominator);

    		return 0;
	}

