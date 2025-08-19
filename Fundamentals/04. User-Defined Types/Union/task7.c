#include <stdio.h>

	typedef union {
    		float usd;
    		float eur;
	} Currency;

	int main() {
    		Currency c;

    		printf("Enter amount in USD: ");
    		scanf("%f", &c.usd);
    
			printf("\nusd = %.2f\n", c.usd);
    		printf("eur (same memory) = %.2f\n", c.eur);

    		printf("\nEnter amount in EUR: ");
    		scanf("%f", &c.eur);
    
			printf("\neur = %.2f\n", c.eur);
    		printf("usd (same memory) = %.2f\n", c.usd);

    		return 0;
	}

