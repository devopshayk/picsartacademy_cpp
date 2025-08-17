#include <stdio.h>

	int digits_sum(int num);

	int main() {
		int num = 0;

		printf("Write num for sum of digits: ");
		scanf("%d", &num);

		int result = digits_sum(num);

		printf("Sum of digits = %d\n", result);

		return 0;		
	}

	
	int digits_sum(int num) {
		if(num == 0) return num;

		return num % 10 + digits_sum(num / 10);
	}
