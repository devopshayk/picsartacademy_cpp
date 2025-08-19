#include <stdio.h>

	typedef struct {
    		float celsius;
    		float fahrenheit;
	} Temperature;

	int main() {
    		Temperature temp;

    		printf("\tEnter temperature in Celsius\n\n");

    		printf("Celsius: ");
    		scanf("%f", &temp.celsius);

    		temp.fahrenheit = (temp.celsius * 9 / 5) + 32;

    		printf("\nCelsius = %.2f\n", temp.celsius);
    		printf("Fahrenheit = %.2f\n", temp.fahrenheit);

    		return 0;
	}

