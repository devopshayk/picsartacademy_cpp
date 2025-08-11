#include <stdio.h>

	int fib(int num);

	int main() {
		int n = 0;

		printf("Write number for search fibonacci num: ");
		scanf("%d", &n);

		printf("%dth number of fibonacci = %d\n", n, fib(n));

		return 0;
	}


	int fib(int num) {
		if(num == 0 || num == 1) return num;

		return fib(num - 1) + fib(num - 2);
	}
