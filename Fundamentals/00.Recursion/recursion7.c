#include <stdio.h>

	int digit_sum(int num);

	int main() {
		int num = 123;

		printf("%d", digit_sum(num));

		return 0;		
	}

	int digit_sum(int num) {
		if(num == 0) return 0;
		
		return num % 10 + digit_sum(num / 10);
	}
