#include <stdio.h>

	float toCelsius(float F);

	int main() {
		float F = 0;
		
		printf("\t Converting Fahrenheit to Celsius\n\n");

		printf("Write value for Fahrenheit: ");
		scanf("%f", &F);

		float result = toCelsius(F);

		printf("%.2f Fahrenheit = %.2f Celsius\n", F, result);

		return 0;
	}

	float toCelsius(float F) {
		float C = (F - 32) * 5 / 9;

		return C;
	}
