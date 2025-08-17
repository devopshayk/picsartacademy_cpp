#include <stdio.h>

	int fibonacci(int index);

	int main() {
		int index = 0;

		printf("Write index for dedtected number: ");
		scanf("%d", &index);

		int result = fibonacci(index);

		puts("");

		printf("Fibonacci's %d'th index = number %d\n", index, result);

		return 0;
	}

	int fibonacci(int index) {
		if (index == 0 || index == 1) return index;

		return fibonacci(index - 1) + fibonacci(index - 2);
	}
