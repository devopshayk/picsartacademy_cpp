#include <stdio.h>
	
	int digits_sum(int num);
		
	int main() {
		int n = 0;

		printf("Write number for digits sum: ");
		scanf("%d", &n);
		
		printf("Digits sum for number %d = %d\n", n, digits_sum(n));

		return 0;
	}

	int digits_sum(int num) {
		if(num == 0) return num;

		return num % 10 + digits_sum(num / 10);
	}
